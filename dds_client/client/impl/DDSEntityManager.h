/* 
 * File name : DDSEntityManager
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSENTITYMANAGER_H__
#define __DDSENTITYMANAGER_H__
#include "IEntityManager.h"
namespace SEMADDS {
	class DDSEntityManager : public IEntityManager
	{
	public:
		DDSEntityManager();
		virtual ~DDSEntityManager();
	};
};
#endif
