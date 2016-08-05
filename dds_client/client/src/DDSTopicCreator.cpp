/* 
 * File name : DDSTopicCreator
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSTopicCreator.h"
#include "DDSManager.h"
#include "DDSParticipant.h"
#include "DDSRegister.h"
using namespace SEMADDS;
DDSTopicCreator::DDSTopicCreator()
{
	service_started = false;
}
DDSTopicCreator::~DDSTopicCreator()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DomainParticipant_var participant = part->GetVar();
	if (!service_started)return;
	long status = participant->delete_topic(_topic);
}

bool SEMADDS::DDSTopicCreator::Create(const char * topic )
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DDSRegister * reg = (DDSRegister *)manager.GetRegister();
	DomainParticipant_var participant = part->GetVar();
	long status = participant->get_default_topic_qos(reliable_topic_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
	reliable_topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
	reliable_topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;

	/* Make the tailored QoS the new default. */
	status = participant->set_default_topic_qos(reliable_topic_qos);
	checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

	/* Use the changed policy when defining the HelloWorld topic */
	_topic = participant->create_topic(topic , reg->GetTypeSupport().get_type_name() , reliable_topic_qos,
		NULL, STATUS_MASK_NONE);
	checkHandle( _topic.in(), "DDS::DomainParticipant::create_topic ()" );

	service_started = true;
	return false;
}

Topic_var SEMADDS::DDSTopicCreator::GetTopic() const
{
	return _topic;
}

bool SEMADDS::DDSTopicCreator::Initialize()
{
	return false;
}

bool SEMADDS::DDSTopicCreator::Start()
{
	return false;
}
