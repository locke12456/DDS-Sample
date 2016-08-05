/* 
 * File name : DDSMessageReader
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSMessageReader.h"
#include "DDSManager.h"
#include "DDSSubscriber.h"
#include "DDSParticipant.h"
#include "DDSTopicCreator.h"
using namespace SEMADDS;
DDSMessageReader::DDSMessageReader()
{
	service_started = false;
}
DDSMessageReader::~DDSMessageReader()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSSubscriber * sub = (DDSSubscriber *)manager.GetSubscriber();
	Subscriber_var subscriber = sub->GetSubscriber();
	if (!service_started)return;
	long status = subscriber->delete_datareader(data_reader);
}

DataReader_var SEMADDS::DDSMessageReader::GetDataReader() const
{
	return data_reader;
}

MessageDataReader_var SEMADDS::DDSMessageReader::GetMessageReader() const
{
	return massage_reader;
}

bool SEMADDS::DDSMessageReader::Initialize()
{
	return false;
}

bool SEMADDS::DDSMessageReader::Start()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DDSSubscriber * sub = (DDSSubscriber *)manager.GetSubscriber();
	DDSTopicCreator * top = (DDSTopicCreator *)manager.GetTopicCreator();
	DomainParticipant_var participant = part->GetVar();
	Subscriber_var subscriber = sub->GetSubscriber();
	Topic_var topic = top->GetTopic();
	data_reader = subscriber->create_datareader(topic.in(),
		DATAREADER_QOS_USE_TOPIC_QOS, NULL, STATUS_MASK_NONE);
	checkHandle(data_reader, "DDS::Subscriber::create_datareader ()");
	massage_reader = MessageDataReader::_narrow(data_reader.in());
	checkHandle(massage_reader.in(), "MessageDataReader::_narrow");
	service_started = true;
	return false;
}
