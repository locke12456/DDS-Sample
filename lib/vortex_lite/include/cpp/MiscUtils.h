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
#ifndef DDS_OPENSPLICE_MISCUTILS_H
#define DDS_OPENSPLICE_MISCUTILS_H


#include "ccpp.h"


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
DDS::ReturnCode_t durationIsValid(const DDS::Duration_t &duration);
DDS::ReturnCode_t timeIsValid    (const DDS::Time_t     &time);

/*
 * Comparison
 */
DDS::Boolean durationIsEqual (const DDS::Duration_t &a, const DDS::Duration_t &b);

/*
 * Conversions
 */
void copyDurationIn (const DDS::Duration_t &from, dds_duration_t &to);
void copyDurationOut (const dds_duration_t &from, DDS::Duration_t &to);

DDS::ReturnCode_t copyDurationInTime (const DDS::Duration_t &from, dds_time_t &to);
DDS::ReturnCode_t copyDurationOutTime (const dds_time_t &from, DDS::Duration_t &to);

DDS::ReturnCode_t copyTimeIn (const DDS::Time_t &from, dds_time_t &to);
void copyTimeOut (const dds_time_t &from, DDS::Time_t &to);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#endif /* DDS_OPENSPLICE_MISCUTILS_H */


