/* 
 * File name : DDSPublisher
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __IDDSOBJECT_H__
#define __IDDSOBJECT_H__
#include "dllexport.h"
namespace SEMADDS {
	class libSemaDDS_EXPORT IDDSObject
	{
	public:
		virtual ~IDDSObject() {};
		virtual bool Initialize() = 0;
		virtual bool Start() = 0;
	protected:
		bool service_started;
	};
};
#endif
