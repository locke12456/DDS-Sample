/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef CPP_SUPERCLASS_H_
#define CPP_SUPERCLASS_H_

#include "ccpp.h"
#include "cpp_dcps_if.h"
#include "sacpp_LocalObject.h"

namespace DDS
{
  namespace OpenSplice
  {
    class EntityContainer;

    typedef enum
    {
      UNDEFINED,

      /* Objects */
      ERRORINFO,
      DOMAINPARTICIPANTFACTORY,
      TYPESUPPORT,
      TYPESUPPORTMETAHOLDER,
      WAITSET,
      __DOMAIN,

      /* Conditions */
      CONDITION,
      STATUSCONDITION,
      GUARDCONDITION,
      READCONDITION,
      QUERYCONDITION,

      /* Entities */
      ENTITY,
      DOMAINPARTICIPANT,
      PUBLISHER,
      SUBSCRIBER,
      DATAWRITER,
      DATAREADER,

      /* Topic Descriptions: */
      TOPICDESCRIPTION,
      TOPIC,
      CONTENTFILTEREDTOPIC,
      MULTITOPIC,

      OBJECT_COUNT
    } ObjectKind;

    class OS_API CppSuperClassInterface : public virtual DDS::LocalObject
    {
    public:

      virtual DDS::ReturnCode_t deinit () = 0;
      virtual DDS::ReturnCode_t wlReq_deinit () = 0;
      virtual DDS::ReturnCode_t lock () = 0;
      virtual void unlock () = 0;
      virtual DDS::ReturnCode_t check () = 0;

      CppSuperClassInterface () {};
      virtual ~CppSuperClassInterface ();

    private:

      CppSuperClassInterface (const CppSuperClassInterface&);
      CppSuperClassInterface &operator= (const CppSuperClassInterface&);
    };

    class OS_API CppSuperClass :
      public virtual CppSuperClassInterface,
      public LOCAL_REFCOUNTED_OBJECT
    {
       friend class ::DDS::OpenSplice::EntityContainer;

    private:

      const ObjectKind objKind;
      DDS::Long callback_count;
      DDS::Boolean deinitialized;
      void * mutex;
      void * cond;
      void * callback_mutex;

    protected:

      CppSuperClass (ObjectKind kind);
      virtual ~CppSuperClass ();

      virtual DDS::ReturnCode_t deinit ();
      virtual DDS::ReturnCode_t wlReq_deinit ();
      void prevent_callbacks ();

    public:

      virtual DDS::ReturnCode_t lock ();
      virtual void unlock ();

      ObjectKind kind () { return objKind; }
      virtual DDS::ReturnCode_t check ();

      DDS::ReturnCode_t get_callback_lock ();
      void release_callback_lock ();
    };
  };
};

#undef OS_API
#endif /* CPP_SUPERCLASS_H_ */
