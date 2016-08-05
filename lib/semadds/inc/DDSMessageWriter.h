/* 
 * File name : DDSMessageWriter
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSMESSAGEWRITER_H__
#define __DDSMESSAGEWRITER_H__
#include "dllexport.h"
#include "ccpp_dds_dcps.h"
#include "ccpp_semadds.h"
#include "CheckStatus.h"
#include "IDDSObject.h"
using namespace SEMADDS_Types;
using namespace DDS;
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSMessageWriter : public IDDSObject
	{
	public:
		DDSMessageWriter();
		virtual ~DDSMessageWriter();
		DataWriter_var GetDataWriter()const;
		MessageDataWriter_var GetMessageWriter()const;
		// Inherited via IDDSObject
		virtual bool Initialize() override;
		virtual bool Start() override;
		bool Start(bool autodispose_unregistered_instances);
	private:

		DataWriterQos dw_qos;

		TopicQos reliable_topic_qos;

		DataWriter_var data_writer;

		MessageDataWriter_var message_writer;
	};
};
#endif
