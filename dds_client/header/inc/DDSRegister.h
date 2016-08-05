/* 
 * File name : DDSRegister
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSREGISTER_H__
#define __DDSREGISTER_H__
#include <list>
#include "IDDSObject.h"
#include "dds_dcps_interfaces.h"
namespace SEMADDS {
	class libSemaDDS_EXPORT DDSRegister : public IDDSObject
	{
	public:
		DDSRegister();
		virtual ~DDSRegister();

		DDS::TypeSupport& GetTypeSupport()const;

		template <class DDSType >
		bool addTypeSupport();
		// Inherited via IDDSObject
		virtual bool Start() override;

		// Inherited via IDDSObject
		virtual bool Initialize() override;
	private:
		bool AddTypeSupport(DDS::TypeSupport * type);
		DDS::TypeSupport * _support;
	};
	template<class DDSType>
	inline bool DDSRegister::addTypeSupport()
	{
		_support = new DDSType();
		return AddTypeSupport(_support);
	}
};
#endif
