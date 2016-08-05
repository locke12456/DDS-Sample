/* 
 * File name : SEMADDSClient
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "SEMADDSClient.h"
#include "DDSManager.h"
#include "boost/thread.hpp"
#include "DDSMessageReader.h"
#include "DDSMessageWriter.h"

typedef boost::thread Worker;
typedef boost::lock_guard<boost::mutex> Guard;
typedef boost::unique_lock<boost::mutex> Lock;
typedef boost::mutex					Mutex;
boost::condition_variable	 _wait, _wait_thread_ready;
Mutex						 _mutex, _thread_mutex;
boost::shared_ptr<Worker>			_worker;
using namespace SEMADDS;

SEMADDSClient::SEMADDSClient()
{
	_thread_ready = false;
	_stop = false;
}

SEMADDSClient::~SEMADDSClient()
{
	Lock lock(_thread_mutex);
	_stop = true;
	if (_thread_ready)
		_wait_thread_ready.wait(lock);
	DDSManager::Destroy();
	std::cout << "destory";
}

bool SEMADDS::SEMADDSClient::Setup(SEMADDSClient::CallBack callbak)
{
	Lock lock(_thread_mutex);
	DDSManager& mgr = DDSManager::getInstance();
	mgr.Setup("SEMADDSClient", "SEMADDS_Message");
	mgr.SetupSubscriber();
	mgr.SetupPubilsher();
	_callbak = callbak;
	_worker = boost::shared_ptr<Worker>(new Worker(boost::bind(&SEMADDSClient::_subscriber, this)));
	if (!_thread_ready)
		_wait_thread_ready.wait(lock);
	return false;
}

bool SEMADDS::SEMADDSClient::publishMessage( int id ,const char * message)
{
	Guard lock(_mutex);
	SampleInfoSeq infoSeq;
	DDSManager& mgr = DDSManager::getInstance();
	DDSMessageWriter* writer = (DDSMessageWriter*)mgr.GetMessageWriter();
	MessageDataWriter_var messageWritter = writer->GetMessageWriter();

	Message MessageInstance; /* Example on Stack */
	MessageInstance.id = id;
	MessageInstance.message = DDS::string_dup(message);
	//cout << "=== [Publisher] writing a message containing :" << endl;
	//cout << "    id  : " << MessageInstance.id << endl;
	//cout << "    Message : \"" << MessageInstance.message << "\"" << endl;

	ReturnCode_t status = messageWritter->write(MessageInstance, DDS::HANDLE_NIL);
	return true;
}

bool SEMADDS::SEMADDSClient::_stopped()
{
	return _stop;
}

void SEMADDS::SEMADDSClient::_subscriber()
{
	DDSManager& mgr = DDSManager::getInstance();
	DDSMessageReader * reader = (DDSMessageReader *)mgr.GetMessageReader();
	MessageDataReader_var msgReader = reader->GetMessageReader();

	os_time delay_2ms = { 0, 2000000 };
	os_time delay_200ms = { 0, 200000000 };
	MessageSeq MessageList;
	SampleInfoSeq infoSeq;
	_thread_ready = true;
	_wait_thread_ready.notify_all();
	while (!_stopped())
	{
		long status = msgReader->take(MessageList, infoSeq, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
		//checkStatus(status, "MessageDataReader::take");
		for (DDS::ULong j = 0; j < MessageList.length(); j++)
		{
			//cout << "=== [Subscriber] message received :" << endl;
			//cout << "    id  : " << MessageList[j].id << endl;
			//cout << "    Message : \"" << MessageList[j].message << "\"" << endl;
			_callbak((int)MessageList[j].id,(void *)MessageList[j].message);
		}
		status = msgReader->return_loan(MessageList, infoSeq);

		os_nanoSleep(delay_200ms);
	}
	_thread_ready = false;
	_wait_thread_ready.notify_all();

	std::cout << "stopped";
}
