/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef LITE_CORE_USEROBJECT_DELEGATE_HPP_
#define LITE_CORE_USEROBJECT_DELEGATE_HPP_

#include "dds/core/macros.hpp"
#include "dds/core/refmacros.hpp"
#include "org/opensplice/core/Mutex.hpp"
#include "org/opensplice/core/ObjectDelegate.hpp"

namespace org
{
  namespace opensplice
  {
    namespace core
    {
      class OMG_DDS_API UserObjectDelegate : public virtual org::opensplice::core::ObjectDelegate
      {
      public:

        UserObjectDelegate ();
        virtual ~UserObjectDelegate ();

        void close ();
        void * get_user_handle ();

      protected:

        void * userHandle;
      };
    }
  }
}

#endif /* LITE_CORE_USEROBJECT_DELEGATE_HPP_ */
