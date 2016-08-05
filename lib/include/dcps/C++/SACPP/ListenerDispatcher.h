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
#ifndef CPP_DDS_OPENSPLICE_LISTENERDISPATCHER_H
#define CPP_DDS_OPENSPLICE_LISTENERDISPATCHER_H

#include "cmn_listenerDispatcher.h"

#include "ccpp.h"
#include "cpp_dcps_if.h"

namespace DDS {

    namespace OpenSplice {

        class OS_API ListenerDispatcher {
        public:
            static os_schedClass
            scheduling_class (
                const DDS::SchedulingQosPolicy &scheduling);

            static os_int32
            scheduling_priority (
                const DDS::SchedulingQosPolicy &scheduling);

            static void
            event_handler (
                v_listenerEvent event,
                c_voidp argument);
        };

}; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_LISTENERDISPATCHER_H */
