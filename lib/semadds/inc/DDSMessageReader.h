/* 
 * File name : DDSMessageReader
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSMESSAGEREADER_H__
#define __DDSMESSAGEREADER_H__
#include "dllexport.h"
#include "ccpp_dds_dcps.h"
#include "ccpp_semadds.h"
#include "CheckStatus.h"
#include "IDDSObject.h"
using namespace SEMADDS_Types;
using namespace DDS;
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSMessageReader : public IDDSObject
	{
	public:
		DDSMessageReader();
		virtual ~DDSMessageReader();
		DataReader_var GetDataReader()const;
		MessageDataReader_var GetMessageReader()const;
		// Inherited via IDDSObject
		virtual bool Initialize() override;
		virtual bool Start() override;
	private:
		MessageDataReader_var massage_reader;
		DataReader_var data_reader;
	};
};
#endif
