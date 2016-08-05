/* 
 * File name : DDSSubscriber
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSSubscriber.h"
#include "DDSManager.h"
#include "DDSParticipant.h"
using namespace SEMADDS;
DDSSubscriber::DDSSubscriber()
{
	service_started = false;
}
DDSSubscriber::~DDSSubscriber()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DomainParticipant_var participant = part->GetVar();
	if (!service_started)return;
	long status = participant->delete_subscriber(subscriber);
}

Subscriber_var SEMADDS::DDSSubscriber::GetSubscriber() const
{
	return subscriber;
}

bool SEMADDS::DDSSubscriber::Initialize()
{
	return false;
}

bool SEMADDS::DDSSubscriber::Start()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DomainParticipant_var participant = part->GetVar();
	int status = participant->get_default_subscriber_qos(sub_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
	sub_qos.partition.name.length(1);
	sub_qos.partition.name[0] = part->GetPartition();
	subscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
	checkHandle(subscriber.in(), "DDS::DomainParticipant::create_subscriber");
	service_started = true;
	return true;
}
