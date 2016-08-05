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
 * @brief This class provides a synchronized output to STDOUT
 *
 * @author Bernard MAUDRY
 *
 * Module   : RMI
 * Class   : Sync_Print
 *
 *
 */

#ifndef SDK_SYNC_PRINT_HPP_
#define SDK_SYNC_PRINT_HPP_

#include "sdk_mutex.h"

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {

      class DDS_SERVICE_API Sync_Print
      {
      public:

        static void
        checkStatus(DDS::ReturnCode_t status, const char *info);
        static void
        checkHandle(void *handle, std::string info);

        /**
         * Returns the name of an error code.
         **/
        static std::string
        getErrorName(DDS::ReturnCode_t status);

        /**
         * @brief formatted output into stdout
         */

        static void
        stdOutFormat(const char* format, ...);

      private:
        static Mutex Synchro;
        static std::string RetCodeName[13];
      };
    }
  }
}
#endif /* SDK_SYNC_PRINT_HPP_ */
