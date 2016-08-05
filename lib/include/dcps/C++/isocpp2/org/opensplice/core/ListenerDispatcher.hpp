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
#ifndef ORG_OPENSPLICE_CORE_LISTENERDISPATCHER_H_
#define ORG_OPENSPLICE_CORE_LISTENERDISPATCHER_H_

#include <dds/core/policy/CorePolicy.hpp>

#include <org/opensplice/core/EntityDelegate.hpp>

#include "u_entity.h"
#include "u_listener.h"
#include "u_participant.h"

#include <set>


namespace org
{
namespace opensplice
{
namespace core
{

class OMG_DDS_API ListenerDispatcher
{
public:
    typedef ::dds::core::smart_ptr_traits< ListenerDispatcher >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< ListenerDispatcher >::weak_ref_type weak_ref_type;

    virtual ~ListenerDispatcher();

    void
    deinit();

    void
    add_listener(org::opensplice::core::EntityDelegate* observable,
                 u_entity uEntity,
                 const dds::core::status::StatusMask& mask);

    void
    remove_listener(org::opensplice::core::EntityDelegate* observable, u_entity uEntity);

    void
    add_source(org::opensplice::core::EntityDelegate* source, u_entity uEntity);

    void
    remove_source(org::opensplice::core::EntityDelegate* source, u_entity uEntity);

private:
    ListenerDispatcher(u_participant participant,
                       const org::opensplice::core::policy::ListenerScheduling& scheduling);

    typedef enum {
       STOPPED,
       STARTING,
       RUNNING,
       STOPPING
    } threadState_t;

    uint32_t
    getStackSize(u_cfElement configuration);

    void
    threadStart();

    static void*
    threadWrapper(
        void *arg);

    void
    thread();

    static void
    eventHandlerWrapper(
        v_listenerEvent event,
        c_voidp         arg);

    void
    eventHandler(
        v_listenerEvent event);

    /* Need to use os_mutex because we want to use a condition variable. */
    os_mutex                  mutex;
    os_cond                   cond;
    os_threadId               threadId;
    threadState_t             threadState;
    uint32_t                  stackSize;
    u_listener                uListener;
    org::opensplice::core::policy::ListenerScheduling scheduling;
    std::set<org::opensplice::core::EntityDelegate*> observables;
    std::multiset<u_entity> invalid_user_entities;
    org::opensplice::core::Mutex entities_mutex;

    static const uint32_t     DEFAULT_STACKSIZE = 0;

public:
    /*
     * Special create and destroy functionallity.
     *
     * The ListenerDispatcher contains a thread. This thread holds strong
     * references (aka shared pointers) to Entities. Because of this,
     * entities can be destructed within the ListenerDispatcher thread
     * context.
     * This, in the end, can mean that the ListenerDispatcher itself is
     * destroyed within its own thread.
     *
     * This causes all kinds of problems, as you can imagine.
     *
     * The simplest solution is not really destroying the ListenerDispatcher
     * when the creator requests it. But instead store it in global strong
     * reference. This way, the ListenerDispatcher is either destroyed when
     * another ListenerDispatchers' destruction is requested (meaning that
     * the pointer in the strong reference is replaced, meaning that the
     * destructor of the stored ListenerDispatcher is called) or with the
     * end of the program when the shared pointer is destroyed and thus its
     * containing ListenerDispatcher as well.
     * This way, you can always ensure that a ListenerDispatcher is not
     * destroyed within its own thread context (it is still possible that
     * it is destroyed in the thread context of another ListenerDispatcher,
     * but that's not a problem).
     */
    static ListenerDispatcher*
    create(u_participant                        participant,
           const org::opensplice::core::policy::ListenerScheduling& scheduling);
    static void
    destroy(ListenerDispatcher* ld);
private:
    static ListenerDispatcher::ref_type livecycle_ref;
    static org::opensplice::core::Mutex livecycle_mutex;
};

}
}
}


#endif /* ORG_OPENSPLICE_CORE_LISTENERDISPATCHER_H_ */
