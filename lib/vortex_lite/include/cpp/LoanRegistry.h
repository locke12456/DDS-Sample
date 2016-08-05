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
#ifndef CPP_DDS_OPENSPLICE_LOANREGISTRY_H
#define CPP_DDS_OPENSPLICE_LOANREGISTRY_H

#include "ccpp.h"
#include "cpp_dcps_if.h"

namespace DDS {
    namespace OpenSplice {

        class Loan;

        /* NOT THREAD SAFE: The caller should enforce thread safety. */
        class OS_API LoanRegistry
        {
        public:
            LoanRegistry();

            virtual ~LoanRegistry();

            DDS::ReturnCode_t
            register_loan(
                void *data_buffer,
                void *info_buffer);

            DDS::ReturnCode_t
            deregister_loan(
                void *data_buffer,
                void *info_buffer);

            DDS::Boolean
            contains_loan(
                void *data_buffer,
                void *info_buffer);

            DDS::Boolean
            is_empty ();

        private:
            Loan*
            list_extract_empty_loan();

            void
            list_insert_loan(Loan *loan);

            void
            list_move_loan_to_end(Loan *loan);

            Loan*
            list_find_loan(
                void *data_buffer,
                void *info_buffer);

            Loan *firstLoan;
            Loan *lastLoan;
        }; /* class DataReader */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_LOANREGISTRY_H */
