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


#ifndef V_INSTANCE_H
#define V_INSTANCE_H

#include "v_kernel.h"

#define v_instance(o) (C_CAST(o,v_instance))

#define v_instanceState(_this) (v_instance(_this)->state)
#define v_instanceSetState(_this, _state) (v_instance(_this)->state = _state)
#define v_instanceEntity(_this) (v_instance(_this)->entity)
#define v_instanceSetEntity(_this, _entity) (v_instance(_this)->entity = _entity)

void
v_instanceInit (
    v_instance _this,
    v_entity entity);

void
v_instanceDeinit (
    v_instance _this);

#endif
