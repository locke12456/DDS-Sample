/* 
 * File name : DDSPublisher
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSPUBILISER_H__
#define __DDSPUBILISER_H__
#include "IDDSObject.h"
#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
using namespace DDS;
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSPublisher : public IDDSObject
	{
	public:
		DDSPublisher();
		virtual ~DDSPublisher();
		Publisher_var GetPublisher()const;
		// Inherited via IDDSObject
		virtual bool Initialize() override;
		virtual bool Start() override;
	private:

		Publisher_var publisher;
		PublisherQos pub_qos;
	};
};
#endif
