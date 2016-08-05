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
#ifndef CCPP_DOMAINPARTICIPANTFACTORY_H
#define CCPP_DOMAINPARTICIPANTFACTORY_H

#include "CppSuperClass.h"
#include "ObjSet.h"
#include "EntityContainer.h"

#include "cpp_dcps_if.h"
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
  namespace OpenSplice
  {
    class DomainParticipant;
    class Domain;
  };

  typedef DomainParticipantFactoryInterface_ptr DomainParticipantFactory_ptr;
  typedef DomainParticipantFactoryInterface_var DomainParticipantFactory_var;

  class OS_API DomainParticipantFactory :
    public virtual DomainParticipantFactoryInterface,
    public ::DDS::OpenSplice::EntityContainer,
    public DDS::OpenSplice::CppSuperClass
  {
  private:

    DDS::DomainParticipantQos defaultParticipantQos;

  protected:

    DomainParticipantFactory ();

  public:

      ~DomainParticipantFactory ();
      static DDS::DomainParticipantFactory_ptr get_instance ();

      static DomainParticipantFactory_ptr _nil () { return NULL; };

      static DomainParticipantFactory_ptr
      _duplicate(DomainParticipantFactory_ptr obj);

      virtual DDS::DomainParticipant_ptr
      create_participant (
              DDS::DomainId_t domainId,
              const DDS::DomainParticipantQos & qos,
              DDS::DomainParticipantListener_ptr a_listener,
              DDS::StatusMask mask
      ) THROW_ORB_EXCEPTIONS;

      virtual DDS::ReturnCode_t
      delete_participant (
              DDS::DomainParticipant_ptr a_participant
      ) THROW_ORB_EXCEPTIONS;

      virtual DDS::DomainParticipant_ptr
      lookup_participant (
              DDS::DomainId_t domainId
      ) THROW_ORB_EXCEPTIONS;

      virtual DDS::ReturnCode_t
      delete_contained_entities (
      ) THROW_ORB_EXCEPTIONS;

      virtual DDS::ReturnCode_t
      set_default_participant_qos (
              const DDS::DomainParticipantQos & qos
      ) THROW_ORB_EXCEPTIONS;

      virtual DDS::ReturnCode_t
      get_default_participant_qos (
              DDS::DomainParticipantQos & qos
      ) THROW_ORB_EXCEPTIONS;
  };
}

#undef OS_API
#endif /* DOMAINPARTICIPANTFACTORY */
