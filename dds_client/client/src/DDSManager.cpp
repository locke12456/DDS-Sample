/* 
 * File name : DDSManager
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */

#include "DDSManager.h"
#include "ccpp_semadds.h"
#include "DDSParticipant.h"
#include "DDSRegister.h"
#include "DDSTopicCreator.h"
#include "DDSSubscriber.h"
#include "DDSPublisher.h"
#include "DDSMessageWriter.h"
#include "DDSMessageReader.h"
using namespace SEMADDS;
using namespace SEMADDS_Types;
DDSManager * DDSManager::_this = NULL;

bool SEMADDS::DDSManager::Initialize()
{
	_dds_participant = new DDSParticipant();
	_dds_register = new DDSRegister();
	_dds_topic_creator = new DDSTopicCreator();
	_dds_subscriber = new DDSSubscriber();
	_dds_publisher = new DDSPublisher();
	_dds_message_reader = new DDSMessageReader();
	_dds_message_writer = new DDSMessageWriter();
	return true;
}

DDSManager::DDSManager() :	_dds_participant(NULL) , _dds_register(NULL) ,
							_dds_message_reader(NULL) , _dds_message_writer(NULL) ,
							_dds_topic_creator(NULL) ,
							_dds_publisher(NULL) , _dds_subscriber(NULL)
{
	_domain = DOMAIN_ID_DEFAULT;
}

DDSManager & SEMADDS::DDSManager::getInstance()
{
	if (!_this)
	{
		_this = new DDSManager();
		_this->Initialize();
	}
	return *_this;
	// TODO: insert return statement here
}

void SEMADDS::DDSManager::Destroy()
{
	if (_this)
	{
		delete _this;
		_this = NULL;
	}
}

DDSManager::~DDSManager()
{
	//mgr.deleteReader();
	//mgr.deleteSubscriber();
	//mgr.deleteTopic();
	//mgr.deleteParticipant();
	delete _dds_message_writer;
	delete _dds_message_reader;
	delete _dds_publisher;
	delete _dds_subscriber;
	delete _dds_topic_creator;
	delete _dds_participant;
}

long SEMADDS::DDSManager::GetDomain() const
{
	return _domain;
}

bool SEMADDS::DDSManager::Setup(const char * domain, const char * topic)
{
	DDSParticipant * part = (DDSParticipant *)_dds_participant;
	DDSRegister * reg = (DDSRegister *)_dds_register;
	DDSTopicCreator * top = (DDSTopicCreator *)_dds_topic_creator;
	part->SetName(domain);
	part->Initialize();
	reg->addTypeSupport<SEMADDS_Types::MessageTypeSupport>();
	top->Create(topic);
	return true;
}

bool SEMADDS::DDSManager::SetupSubscriber()
{
	_dds_subscriber->Start();
	_dds_message_reader->Start();
	return false;
}

bool SEMADDS::DDSManager::SetupPubilsher()
{
	_dds_publisher->Start();
	_dds_message_writer->Start();
	return false;
}



IDDSObject * SEMADDS::DDSManager::GetParticipant() const
{
	return _dds_participant;
}

IDDSObject * SEMADDS::DDSManager::GetRegister() const
{
	return _dds_register;
}

IDDSObject * SEMADDS::DDSManager::GetPublisher() const
{
	return _dds_publisher;
}

IDDSObject * SEMADDS::DDSManager::GetSubscriber() const
{
	return _dds_subscriber;
}

IDDSObject * SEMADDS::DDSManager::GetMessageReader() const
{
	return _dds_message_reader;
}

IDDSObject * SEMADDS::DDSManager::GetMessageWriter() const
{
	return _dds_message_writer;
}

IDDSObject * SEMADDS::DDSManager::GetTopicCreator() const
{
	return _dds_topic_creator;
}
