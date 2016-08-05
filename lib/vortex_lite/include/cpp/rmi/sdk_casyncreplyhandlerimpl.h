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

/**
 * @file
 *
 * @brief Base class of all the asynchronous requests handlers.
 *  Derived by generated code to implement handleReply method.
 *
 * @author Bernard MAUDRY
 *
 *
 * Module   : RMI
 * Class   : CAsyncReplyHandlerImpl
 *
 *
 */

#ifndef SDK_CASYNCREPLYHANDLER_HPP_
#define SDK_CASYNCREPLYHANDLER_HPP_

#include "dds_service_sdk.h"

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {

      class DDS_SERVICE_API CAsyncReplyHandlerImpl : public CAsyncReplyHandler
      {
      public:
        CAsyncReplyHandlerImpl() :
          bActive(false)
        {
        }

        /**
         * @brief called by the Runtime to wait for the reply.
         */
        virtual void
        asyncWait(DDS::QueryCondition * query);

        /**
         * @brief Called by the runtime to process the reply by the user application
         */
        virtual void
        handleReply(DDS::ReadCondition * query) = 0;

        /**
         * @brief Called by the runtime to stop the ReplyWaiter thread
         */
        static void
        terminate();

        bool bActive;
      };
    }

  }
}

#endif /* SDK_CASYNCREPLYHANDLER_HPP_ */
