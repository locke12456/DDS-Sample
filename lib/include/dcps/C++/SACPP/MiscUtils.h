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
#ifndef DDS_OPENSPLICE_MISCUTILS_H
#define DDS_OPENSPLICE_MISCUTILS_H


#include "ccpp.h"
#include "u_user.h"
#include "cpp_dcps_if.h"


/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */


namespace DDS {
namespace OpenSplice {
namespace Utils {


/*
 * There isn't currently a better spot to hold these functions.
 */


/*
 * Validations
 */
DDS::ReturnCode_t booleanIsValid (const DDS::Boolean    value);
DDS::ReturnCode_t durationIsValid(const DDS::Duration_t &duration);
DDS::ReturnCode_t timeIsValid    (const DDS::Time_t     &time);

/*
 * Comparison
 */
DDS::Boolean durationIsEqual (
    const DDS::Duration_t &a,
    const DDS::Duration_t &b);

DDS::Boolean timeIsEqual (
    const DDS::Time_t &a,
    const DDS::Time_t &b);

/*
 * Conversions
 */
DDS::ReturnCode_t  copyDurationIn (const DDS::Duration_t &from, v_duration      &to);
DDS::ReturnCode_t  copyDurationOut(const v_duration      &from, DDS::Duration_t &to);

DDS::ReturnCode_t  copyDurationInTime (const DDS::Duration_t &from, u_time          &to);
DDS::ReturnCode_t  copyDurationOutTime(const u_time          &from, DDS::Duration_t &to);

DDS::ReturnCode_t  copyTimeIn (const DDS::Time_t &from, u_time      &to);
DDS::ReturnCode_t  copyTimeOut(const u_time      &from, DDS::Time_t &to);

OS_API const DDS::Char* returnCodeToString(DDS::ReturnCode_t code);

DDS::ReturnCode_t observableExists(u_observable observable);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#undef OS_API

#endif /* DDS_OPENSPLICE_MISCUTILS_H */


