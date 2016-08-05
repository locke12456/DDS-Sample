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
#ifndef DDS_OPENSPLICE_STATUSUTILS_H
#define DDS_OPENSPLICE_STATUSUTILS_H

#include "ccpp.h"


/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */


namespace DDS {
namespace OpenSplice {
namespace Utils {


/*
 * Flag groups
 */
#define SAMPLE_STATE_FLAGS \
        (DDS::READ_SAMPLE_STATE | \
         DDS::NOT_READ_SAMPLE_STATE)

#define VIEW_STATE_FLAGS \
        (DDS::NEW_VIEW_STATE | \
         DDS::NOT_NEW_VIEW_STATE)

#define INSTANCE_STATE_FLAGS \
        (DDS::ALIVE_INSTANCE_STATE | \
         DDS::NOT_ALIVE_DISPOSED_INSTANCE_STATE | \
         DDS::NOT_ALIVE_NO_WRITERS_INSTANCE_STATE)

#define statesMask(sample_states, view_states, instance_states) \
        ((sample_states & SAMPLE_STATE_FLAGS) | \
         ((view_states & VIEW_STATE_FLAGS) << 2) | \
         ((instance_states & INSTANCE_STATE_FLAGS) << 4))

/*
 * Validations
 */
#define sampleStateMaskIsValid(mask) \
        ((DDS::Boolean)((mask == DDS::ANY_SAMPLE_STATE) || \
                       ((mask & ~SAMPLE_STATE_FLAGS) == 0)))

#define viewStateMaskIsValid(mask) \
        ((DDS::Boolean)((mask == DDS::ANY_VIEW_STATE) || \
                       ((mask & ~VIEW_STATE_FLAGS) == 0)))

#define instanceStateMaskIsValid(mask) \
        ((DDS::Boolean)((mask == DDS::ANY_INSTANCE_STATE) || \
                       ((mask & ~INSTANCE_STATE_FLAGS) == 0)))

#define statesMaskIsValid(sample_states, view_states, instance_states) \
        ((DDS::Boolean) (sampleStateMaskIsValid(sample_states)) && \
                        (viewStateMaskIsValid(view_states)) && \
                        (instanceStateMaskIsValid(instance_states)))

/* If length is unlimited, but release is true, maxSamples equals the
 * maximum for the sequence (scdds2032). */
#define realMaxSamples(max_samples, seq) \
    (((max_samples == DDS::LENGTH_UNLIMITED) && (seq.release())) ? seq.maximum() : max_samples)
/*
 * Status conversions
 */

void copyStatusOut( const dds_offered_incompatible_qos_status_t &from,
                            OfferedIncompatibleQosStatus &to ) ;
void copyStatusOut( const dds_requested_incompatible_qos_status &from,
                            RequestedIncompatibleQosStatus &to);
void copyStatusOut( const dds_requested_deadline_missed_status &from,
                            RequestedDeadlineMissedStatus &to);
void copyStatusOut( const dds_sample_rejected_status_t &from,
                            SampleRejectedStatus &to);
void copyStatusOut( const dds_liveliness_changed_status_t &from,
                            LivelinessChangedStatus &to);
void copyStatusOut( const dds_subscription_matched_status &from,
                            SubscriptionMatchedStatus &to);
void copyStatusOut( const dds_sample_lost_status &from,
                            SampleLostStatus &to);
void copyStatusOut( const dds_inconsistent_topic_status_t &from,
                            InconsistentTopicStatus        &to);
void copyStatusOut( const dds_offered_deadline_missed_status_t &from,
                            OfferedDeadlineMissedStatus &to ) ;
void copyStatusOut( const dds_liveliness_lost_status_t &from,
                            LivelinessLostStatus &to ) ;
void copyStatusOut( const dds_publication_matched_status_t &from,
                            PublicationMatchedStatus &to ) ;
/* Not yet found in user layer or kernel (not properly searched yet anyway).
void copyStatusOut(const gapi_allDataDisposedTopicStatus &from,     AllDataDisposedTopicStatus &to);
void copyStatusOut(const gapi_sampleRejectedStatusKind &from,       SampleRejectedStatusKind &to);
*/

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#endif /* DDS_OPENSPLICE_STATUSUTILS_H */


