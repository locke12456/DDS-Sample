/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef DDS_SERVICEINTERFACEIMPL_H_
#define DDS_SERVICEINTERFACEIMPL_H_


#include <sdk_cruntimeimpl.h>

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {


class DDS_SERVICE_API dds_serviceinterfaceimpl : public org::opensplice::DDS_RMI::DDS_ServiceInterface
{
public:
  dds_serviceinterfaceimpl(CRuntime_ref runtime);

  virtual
  ~dds_serviceinterfaceimpl();

//  template<class T1, class T2>
//  bool
//  register_interface(shared_ptr<T2> l_SrvProvider,
//        const std::string &p_sServerName, int p_iServerInstanceID);

  virtual bool
  unregister_interface(const std::string &p_sServerName,
              int p_iServerInstanceID);

  bool
  run(const std::string &p_sServerName);

  virtual bool
  shutdown(const std::string &p_sServerName);

  bool
  is_running(const std::string &p_sServerName);

//  template<class T>
//  bool
//  getServerProxy(const std::string & p_sServerName,
//        int p_iProxyInstanceID, shared_ptr<T> &p_ServerProxy);
//
//  template<class T>
//  bool
//  getServerProxy(const std::string & p_sServerName,
//      int p_iServerInstanceID, int p_iProxyInstanceID,
//      shared_ptr<T> &p_ServerProxy);

//private:
//  CRuntime_ref runtime;
};

    }
  }
}

#endif /* DDS_SERVICEINTERFACEIMPL_H_ */
