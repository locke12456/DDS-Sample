/* 
 * File name : DDSTopicCreator
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSTOPICCREATOR_H__
#define __DDSTOPICCREATOR_H__


#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
#include "IDDSObject.h"
using namespace DDS;
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSTopicCreator : public IDDSObject
	{
	public:
		DDSTopicCreator();
		virtual ~DDSTopicCreator();
		bool Create(const char * topic);
		Topic_var GetTopic()const;
		// Inherited via IDDSObject
		virtual bool Initialize() override;
		virtual bool Start() override;
	private:
		Topic_var _topic;
		TopicQos reliable_topic_qos;
		TopicQos setting_topic_qos;
	};
};
#endif
