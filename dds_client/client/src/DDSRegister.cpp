/* 
 * File name : DDSRegister
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "DDSRegister.h"
#include "DDSManager.h"
#include "DDSParticipant.h"
using namespace SEMADDS;

DDSRegister::DDSRegister()
{
	service_started = false;
}

DDSRegister::~DDSRegister()
{

}

DDS::TypeSupport & SEMADDS::DDSRegister::GetTypeSupport() const
{
	return *_support;
}

bool SEMADDS::DDSRegister::AddTypeSupport(DDS::TypeSupport * type)
{
	DDSManager & manager = DDSManager::getInstance();
	DDSParticipant * part = (DDSParticipant *) manager.GetParticipant();

	DDS::String_var typeName = type->get_type_name();
	long status = type->register_type( part->GetVar().in() , typeName);
	checkStatus(status, "register_type");
	service_started = true;
	return true;
}

bool SEMADDS::DDSRegister::Start()
{
	return false;
}

bool SEMADDS::DDSRegister::Initialize()
{
	return true;
}
