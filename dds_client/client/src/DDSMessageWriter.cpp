/* 
 * File name : DDSMessageWriter
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSMessageWriter.h"
#include "DDSManager.h"
#include "DDSPublisher.h"
#include "DDSParticipant.h"
#include "DDSTopicCreator.h"
using namespace SEMADDS;
DDSMessageWriter::DDSMessageWriter()
{
	service_started = false;
}
DDSMessageWriter::~DDSMessageWriter()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSPublisher * pub = (DDSPublisher *)manager.GetPublisher();
	Publisher_var publisher = pub->GetPublisher();
	if (!service_started)return;
	long status = publisher->delete_datawriter(data_writer);
}

DataWriter_var SEMADDS::DDSMessageWriter::GetDataWriter() const
{
	return data_writer;
}

MessageDataWriter_var SEMADDS::DDSMessageWriter::GetMessageWriter() const
{
	return message_writer;
}

bool SEMADDS::DDSMessageWriter::Initialize()
{
	return false;
}

bool SEMADDS::DDSMessageWriter::Start(bool autodispose_unregistered_instances)
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DDSPublisher * pub = (DDSPublisher *)manager.GetPublisher();
	DDSTopicCreator * top = (DDSTopicCreator *)manager.GetTopicCreator();
	Publisher_var publisher = pub->GetPublisher();
	DomainParticipant_var participant = part->GetVar();
	Topic_var topic = top->GetTopic();

	long status = publisher->get_default_datawriter_qos(dw_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	
	status = publisher->copy_from_topic_qos(dw_qos, reliable_topic_qos);
	checkStatus(status, "DDS::Publisher::copy_from_topic_qos");
	// Set autodispose to false so that you can start
	// the subscriber after the publisher
	
	dw_qos.writer_data_lifecycle.autodispose_unregistered_instances =
		autodispose_unregistered_instances;
	
	data_writer = publisher->create_datawriter(topic.in(), dw_qos, NULL,
		STATUS_MASK_NONE);

	checkHandle(data_writer, "DDS::Publisher::create_datawriter");
	
	message_writer = MessageDataWriter::_narrow(data_writer.in());

	service_started = true;
	return true;
}
bool SEMADDS::DDSMessageWriter::Start()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DDSPublisher * pub = (DDSPublisher *)manager.GetPublisher();
	DDSTopicCreator * top = (DDSTopicCreator *)manager.GetTopicCreator();
	Publisher_var publisher = pub->GetPublisher();
	DomainParticipant_var participant = part->GetVar();
	Topic_var topic = top->GetTopic();
	data_writer = publisher->create_datawriter(topic.in(),
		DATAWRITER_QOS_USE_TOPIC_QOS, NULL, STATUS_MASK_NONE);
	message_writer = MessageDataWriter::_narrow(data_writer.in());

	service_started = true;
	return true;
}
