/* 
 * File name : DDSPublisher
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSPublisher.h"
#include "DDSManager.h"
#include "DDSParticipant.h"
using namespace SEMADDS;
DDSPublisher::DDSPublisher()
{
	service_started = false;
}
DDSPublisher::~DDSPublisher()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DomainParticipant_var participant = part->GetVar();
	if (!service_started)return;
	long status = participant->delete_publisher(publisher);
}

Publisher_var SEMADDS::DDSPublisher::GetPublisher() const
{
	return publisher;
}

bool SEMADDS::DDSPublisher::Initialize()
{
	return false;
}

bool SEMADDS::DDSPublisher::Start()
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *)manager.GetParticipant();
	DomainParticipant_var participant = part->GetVar();
	long status = participant->get_default_publisher_qos(pub_qos);
	checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
	pub_qos.partition.name.length(1);
	pub_qos.partition.name[0] = part->GetPartition();

	publisher = participant->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
	checkHandle(publisher.in(), "DDS::DomainParticipant::create_publisher");
	service_started = true;
	return true;
}
