/* 
 * File name : DDSParticipant
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSParticipant.h"
#include "DDSManager.h"
using namespace SEMADDS;
DDSParticipant::DDSParticipant()
{
	service_started = false;
}

DDSParticipant::~DDSParticipant()
{
	if (!service_started)return;
	long status = _dds_particiant->delete_participant(_participant.in());
	checkStatus(status, "DDS::DomainParticipant::delete_participant ");
}

void SEMADDS::DDSParticipant::SetName(std::string name)
{
	_partitiontName = name;
}

DomainParticipant_var SEMADDS::DDSParticipant::GetVar() const
{
	return _participant;
}

DDS::String_var SEMADDS::DDSParticipant::GetPartition() const
{
	return _partition;
}

bool SEMADDS::DDSParticipant::Start()
{
	return false;
}

bool SEMADDS::DDSParticipant::Initialize()
{
	DomainId_t domain = DDSManager::getInstance().GetDomain();
	_dds_particiant = DomainParticipantFactory::get_instance();
	_participant = _dds_particiant->create_participant( domain, PARTICIPANT_QOS_DEFAULT, NULL,
		STATUS_MASK_NONE);
	_partition = _partitiontName.c_str();
	service_started = true;
	return _participant.in();
}
