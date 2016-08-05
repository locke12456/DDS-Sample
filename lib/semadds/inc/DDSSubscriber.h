/* 
 * File name : DDSSubscriber
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSSUBSCRIBER_H__
#define __DDSSUBSCRIBER_H__
#include "IDDSObject.h"
#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
using namespace DDS;

namespace SEMADDS {
	class libSemaDDS_EXPORT DDSSubscriber : public IDDSObject
	{
	public:
		DDSSubscriber();
		virtual ~DDSSubscriber();
		Subscriber_var GetSubscriber()const;
		// Inherited via IDDSObject
		virtual bool Initialize() override;
		virtual bool Start() override;
	private:

		Subscriber_var subscriber;
		SubscriberQos sub_qos;
	};
};
#endif
