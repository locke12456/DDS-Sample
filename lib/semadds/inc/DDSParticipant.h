/* 
 * File name : DDSParticipant
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSPARTICIPANT_H__
#define __DDSPARTICIPANT_H__
#include "IDDSObject.h"

#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
using namespace DDS;
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSParticipant : public IDDSObject
	{
	public:
		DDSParticipant();
		virtual ~DDSParticipant();
		void SetName(std::string name);

		DomainParticipant_var GetVar() const;
		DDS::String_var GetPartition()const;
		virtual bool Start() override;
		virtual bool Initialize() override;

	private:
		std::string _partitiontName;
		DDS::String_var _partition;
		DomainParticipantFactory_var _dds_particiant;
		DomainParticipant_var _participant;


		// Inherited via IDDSObject

	};
};
#endif
