#include "semaddsDcps_impl.h"
#include "semaddsSplDcps.h"
//#include "semadds_export.h"

extern v_copyin_result
__SEMADDS_Types_Message__copyIn (
    c_base base,
    const struct SEMADDS_Types::Message *from,
    struct _SEMADDS_Types_Message *to);

extern void
__SEMADDS_Types_Message__copyOut (
    const void *_from,
    void *_to);

// DDS SEMADDS_Types::Message TypeSupportMetaHolder Object Body
SEMADDS_Types::MessageTypeSupportMetaHolder::MessageTypeSupportMetaHolder () :
        DDS::OpenSplice::TypeSupportMetaHolder ("SEMADDS_Types::Message", "", "id")
{
    copyIn = (DDS::OpenSplice::cxxCopyIn) __SEMADDS_Types_Message__copyIn;
    copyOut = (DDS::OpenSplice::cxxCopyOut) __SEMADDS_Types_Message__copyOut;
    metaDescriptorArrLength = 2;
    metaDescriptorLength = 192;
    const char *tmp[] = {"<MetaData version=\"1.0.0\"><Module name=\"SEMADDS_Types\"><Struct name=\"Message\"><Member name=\"id\">",
"<Long/></Member><Member name=\"message\"><String/></Member></Struct></Module></MetaData>"};
    metaDescriptor = new const char*[metaDescriptorArrLength];
    memcpy(metaDescriptor, tmp, sizeof(tmp));
}

SEMADDS_Types::MessageTypeSupportMetaHolder::~MessageTypeSupportMetaHolder ()
{
    // Rely on parent destructor.
}

::DDS::OpenSplice::DataWriter *
SEMADDS_Types::MessageTypeSupportMetaHolder::create_datawriter ()
{
    return new SEMADDS_Types::MessageDataWriter_impl();
}

::DDS::OpenSplice::DataReader *
SEMADDS_Types::MessageTypeSupportMetaHolder::create_datareader ()
{
    return new SEMADDS_Types::MessageDataReader_impl();
}

::DDS::OpenSplice::DataReaderView *
SEMADDS_Types::MessageTypeSupportMetaHolder::create_view ()
{
    return new SEMADDS_Types::MessageDataReaderView_impl();
}

// DDS SEMADDS_Types::Message TypeSupport Object Body
SEMADDS_Types::MessageTypeSupport::MessageTypeSupport () :
        DDS::OpenSplice::TypeSupport()
{
    tsMetaHolder = new SEMADDS_Types::MessageTypeSupportMetaHolder();
}

SEMADDS_Types::MessageTypeSupport::~MessageTypeSupport ()
{
    DDS::release(tsMetaHolder);
}

// DDS SEMADDS_Types::Message DataWriter_impl Object Body
SEMADDS_Types::MessageDataWriter_impl::MessageDataWriter_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::MessageDataWriter_impl::~MessageDataWriter_impl ()
{
    // Parent destructor takes care of everything.
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::init (
        DDS::OpenSplice::Publisher *publisher,
        DDS::OpenSplice::DomainParticipant *participant,
        const DDS::DataWriterQos &qos,
        DDS::OpenSplice::Topic *a_topic,
        const char *name,
        DDS::OpenSplice::cxxCopyIn copyIn,
        DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataWriter_impl::nlReq_init(publisher, participant, qos, a_topic, name, copyIn, copyOut);
}

::DDS::InstanceHandle_t
SEMADDS_Types::MessageDataWriter_impl::register_instance (
    const SEMADDS_Types::Message & instance_data) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::register_instance(&instance_data);
}

::DDS::InstanceHandle_t
SEMADDS_Types::MessageDataWriter_impl::register_instance_w_timestamp (
    const Message & instance_data,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::unregister_instance (
    const SEMADDS_Types::Message & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::unregister_instance(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::unregister_instance_w_timestamp (
    const Message & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::write (
    const SEMADDS_Types::Message & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::write(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::write_w_timestamp (
    const Message & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::dispose (
    const SEMADDS_Types::Message & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::dispose(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::dispose_w_timestamp (
    const Message & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::writedispose (
    const SEMADDS_Types::Message & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::writedispose(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::writedispose_w_timestamp (
    const Message & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataWriter_impl::get_key_value (
    Message & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::MessageDataWriter_impl::lookup_instance (
    const SEMADDS_Types::Message & instance_data) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::lookup_instance(&instance_data);
}

// DDS SEMADDS_Types::Message DataReader_impl Object Body
SEMADDS_Types::MessageDataReader_impl::MessageDataReader_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::MessageDataReader_impl::~MessageDataReader_impl ()
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::init (
    DDS::OpenSplice::Subscriber *subscriber,
    const DDS::DataReaderQos &qos,
    DDS::OpenSplice::TopicDescription *a_topic,
    const char *name,
    DDS::OpenSplice::cxxCopyIn copyIn,
    DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataReader_impl::nlReq_init(
            subscriber, qos, a_topic, name, copyIn, copyOut,
            this->dataSeqAlloc, this->dataSeqLength, this->dataSeqGetBuffer, this->dataSeqCopyOut);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read_next_sample (
    SEMADDS_Types::Message & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::read_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take_next_sample (
    SEMADDS_Types::Message & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::take_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read_next_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take_next_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::read_next_instance_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::take_next_instance_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::return_loan (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t result = ::DDS::RETCODE_OK;

    result = this->write_lock ();
    if (result == DDS::RETCODE_OK) {
        if ( received_data.length() > 0 ) {
            if (received_data.length() == info_seq.length() &&
                received_data.release() == info_seq.release() ) {
                if (!received_data.release()) {
                    result = DDS::OpenSplice::FooDataReader_impl::wlReq_return_loan( received_data.get_buffer(),
                                                                                     info_seq.get_buffer() );
                    if ( result == ::DDS::RETCODE_OK ) {
                        if ( !received_data.release() ) {
                            SEMADDS_Types::MessageSeq::freebuf( received_data.get_buffer(false) );
                            received_data.replace(0, 0, NULL, false);
                            ::DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                            info_seq.replace(0, 0, NULL, false);
                        }
                    }
                }
            } else {
                result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
        this->unlock();
    }
    return result;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::get_key_value (
    SEMADDS_Types::Message & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::MessageDataReader_impl::lookup_instance (
    const SEMADDS_Types::Message & instance) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::lookup_instance(&instance);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReader_impl::check_preconditions (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples)
{
    if ((max_samples < 0) && (max_samples != DDS::LENGTH_UNLIMITED)) {
        return DDS::RETCODE_BAD_PARAMETER;
    }

    /* Rule 1 : The values of len, max_len, and owns
     * for the two collections must be identical.
     */
    if ((received_data.length()  != info_seq.length())  ||
        (received_data.maximum() != info_seq.maximum()) ||
        (received_data.release() != info_seq.release()))
    {
        return DDS::RETCODE_PRECONDITION_NOT_MET;
    }

    /* Rule 4: If the input max_len>0 and the input owns==FALSE,
     * then the read operation will fail.
     */
    if ((info_seq.maximum() > 0) &&
        (info_seq.release() == false))
    {
        return DDS::RETCODE_PRECONDITION_NOT_MET;
    }

    /* Rule 5: If input max_len>0 and the input owns==TRUE,
     * then the read operation will...
     */
    if (info_seq.maximum() > 0) { /* owns is true, because of rule 4. */
        /* Rule 5a: If max_samples = LENGTH_UNLIMITED,
         * then at most max_len values will be copied.
         * Rule 5b: If max_samples <= max_len,
         * then at most max_samples values will be copied.
         */
        /* Rule 5c: If max_samples > max_len,
         * then the read operation will fail.
         */
        if ((max_samples != DDS::LENGTH_UNLIMITED) &&
            ((DDS::ULong)max_samples > info_seq.maximum())) {
            return DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }

    if ((max_samples == 0) ||
        ((info_seq.maximum() == 0) && (info_seq.release()))) {
        return DDS::RETCODE_NO_DATA;
    }

    return DDS::RETCODE_OK;
}

void *
SEMADDS_Types::MessageDataReader_impl::dataSeqAlloc (
    void * received_data,
    DDS::ULong len)
{
    SEMADDS_Types::MessageSeq *data_seq = reinterpret_cast<SEMADDS_Types::MessageSeq *>(received_data);
    data_seq->replace(len, len, data_seq->allocbuf(len), false);
    return data_seq->get_buffer();
}

void *
SEMADDS_Types::MessageDataReader_impl::dataSeqGetBuffer (
    void * received_data,
    DDS::ULong index)
{
	SEMADDS_Types::MessageSeq *data_seq = reinterpret_cast<SEMADDS_Types::MessageSeq *>(received_data);
	return &((*data_seq)[index]);
}

void
SEMADDS_Types::MessageDataReader_impl::dataSeqLength (
    void * received_data,
    DDS::ULong len)
{
    SEMADDS_Types::MessageSeq *data_seq = reinterpret_cast<SEMADDS_Types::MessageSeq *>(received_data);
    data_seq->length(len);
}

void
SEMADDS_Types::MessageDataReader_impl::dataSeqCopyOut (
    const void * from,
    void * to)
{
    SEMADDS_Types::Message *data = reinterpret_cast<SEMADDS_Types::Message *>(to);
    __SEMADDS_Types_Message__copyOut(from, data);
}

void
SEMADDS_Types::MessageDataReader_impl::copyDataOut (
    const void * from,
    void * to)
{
    SEMADDS_Types::Message *data = reinterpret_cast<SEMADDS_Types::Message *>(to);
    __SEMADDS_Types_Message__copyOut(from, data);
}


// DDS SEMADDS_Types::Message DataReaderView_impl Object Body
SEMADDS_Types::MessageDataReaderView_impl::MessageDataReaderView_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::MessageDataReaderView_impl::~MessageDataReaderView_impl ()
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::init (
    DDS::OpenSplice::DataReader *reader,
    const char *name,
    const DDS::DataReaderViewQos &qos,
    DDS::OpenSplice::cxxCopyIn copyIn,
    DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataReaderView_impl::nlReq_init(
            reader, name, qos, copyIn, copyOut, SEMADDS_Types::MessageDataReader_impl::dataSeqAlloc,
            SEMADDS_Types::MessageDataReader_impl::dataSeqLength);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read_next_sample (
    SEMADDS_Types::Message & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::read_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take_next_sample (
    SEMADDS_Types::Message & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::take_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read_next_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take_next_instance (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::read_next_instance_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::take_next_instance_w_condition (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::MessageDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::return_loan (
    SEMADDS_Types::MessageSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t result = ::DDS::RETCODE_OK;

    result = this->write_lock ();
    if (result == DDS::RETCODE_OK) {
        if ( received_data.length() > 0 ) {
            if (received_data.length() == info_seq.length() &&
                received_data.release() == info_seq.release() ) {
                if (!received_data.release()) {
                    result = DDS::OpenSplice::FooDataReaderView_impl::wlReq_return_loan( received_data.get_buffer(),
                                                           info_seq.get_buffer() );

                    if ( result == ::DDS::RETCODE_OK ) {
                        if ( !received_data.release() ) {
                            SEMADDS_Types::MessageSeq::freebuf( received_data.get_buffer(false) );
                            received_data.replace(0, 0, NULL, false);
                            ::DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                            info_seq.replace(0, 0, NULL, false);
                        }
                    } else if ( result == ::DDS::RETCODE_NO_DATA ) {
                        if ( received_data.release() ) {
                            result = ::DDS::RETCODE_OK;
                        } else {
                            result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
                        }
                    }
                }
            } else {
                result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
        this->unlock();
    }
    return result;
}

::DDS::ReturnCode_t
SEMADDS_Types::MessageDataReaderView_impl::get_key_value (
    SEMADDS_Types::Message & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::MessageDataReaderView_impl::lookup_instance (
    const SEMADDS_Types::Message & instance) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::lookup_instance(&instance);
}
extern v_copyin_result
__SEMADDS_Types_SemaEApi__copyIn (
    c_base base,
    const struct SEMADDS_Types::SemaEApi *from,
    struct _SEMADDS_Types_SemaEApi *to);

extern void
__SEMADDS_Types_SemaEApi__copyOut (
    const void *_from,
    void *_to);

// DDS SEMADDS_Types::SemaEApi TypeSupportMetaHolder Object Body
SEMADDS_Types::SemaEApiTypeSupportMetaHolder::SemaEApiTypeSupportMetaHolder () :
        DDS::OpenSplice::TypeSupportMetaHolder ("SEMADDS_Types::SemaEApi", "", "id")
{
    copyIn = (DDS::OpenSplice::cxxCopyIn) __SEMADDS_Types_SemaEApi__copyIn;
    copyOut = (DDS::OpenSplice::cxxCopyOut) __SEMADDS_Types_SemaEApi__copyOut;
    metaDescriptorArrLength = 7;
    metaDescriptorLength = 726;
    const char *tmp[] = {"<MetaData version=\"1.0.0\"><Module name=\"SEMADDS_Types\"><Enum name=\"APIKind\"><Element name=\"SemaEApiBoardValue\" value=\"0\"/>",
"<Element name=\"SemaEApiCPUValue\" value=\"1\"/></Enum><Struct name=\"BoardValue\"><Member name=\"id\">",
"<ULong/></Member><Member name=\"Value\"><ULong/></Member></Struct><Union name=\"API\"><SwitchType><Type name=\"APIKind\"/>",
"</SwitchType><Case name=\"SemaEApiBoardValue\"><Type name=\"BoardValue\"/><Label value=\"SemaEApiBoardValue\"/>",
"</Case><Case name=\"SemaEApiCPUValue\"><Type name=\"BoardValue\"/><Label value=\"SemaEApiCPUValue\"/>",
"</Case></Union><Struct name=\"SemaEApi\"><Member name=\"id\"><ULong/></Member><Member name=\"Api\"><Type name=\"API\"/>",
"</Member></Struct></Module></MetaData>"};
    metaDescriptor = new const char*[metaDescriptorArrLength];
    memcpy(metaDescriptor, tmp, sizeof(tmp));
}

SEMADDS_Types::SemaEApiTypeSupportMetaHolder::~SemaEApiTypeSupportMetaHolder ()
{
    // Rely on parent destructor.
}

::DDS::OpenSplice::DataWriter *
SEMADDS_Types::SemaEApiTypeSupportMetaHolder::create_datawriter ()
{
    return new SEMADDS_Types::SemaEApiDataWriter_impl();
}

::DDS::OpenSplice::DataReader *
SEMADDS_Types::SemaEApiTypeSupportMetaHolder::create_datareader ()
{
    return new SEMADDS_Types::SemaEApiDataReader_impl();
}

::DDS::OpenSplice::DataReaderView *
SEMADDS_Types::SemaEApiTypeSupportMetaHolder::create_view ()
{
    return new SEMADDS_Types::SemaEApiDataReaderView_impl();
}

// DDS SEMADDS_Types::SemaEApi TypeSupport Object Body
SEMADDS_Types::SemaEApiTypeSupport::SemaEApiTypeSupport () :
        DDS::OpenSplice::TypeSupport()
{
    tsMetaHolder = new SEMADDS_Types::SemaEApiTypeSupportMetaHolder();
}

SEMADDS_Types::SemaEApiTypeSupport::~SemaEApiTypeSupport ()
{
    DDS::release(tsMetaHolder);
}

// DDS SEMADDS_Types::SemaEApi DataWriter_impl Object Body
SEMADDS_Types::SemaEApiDataWriter_impl::SemaEApiDataWriter_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::SemaEApiDataWriter_impl::~SemaEApiDataWriter_impl ()
{
    // Parent destructor takes care of everything.
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::init (
        DDS::OpenSplice::Publisher *publisher,
        DDS::OpenSplice::DomainParticipant *participant,
        const DDS::DataWriterQos &qos,
        DDS::OpenSplice::Topic *a_topic,
        const char *name,
        DDS::OpenSplice::cxxCopyIn copyIn,
        DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataWriter_impl::nlReq_init(publisher, participant, qos, a_topic, name, copyIn, copyOut);
}

::DDS::InstanceHandle_t
SEMADDS_Types::SemaEApiDataWriter_impl::register_instance (
    const SEMADDS_Types::SemaEApi & instance_data) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::register_instance(&instance_data);
}

::DDS::InstanceHandle_t
SEMADDS_Types::SemaEApiDataWriter_impl::register_instance_w_timestamp (
    const SemaEApi & instance_data,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::unregister_instance (
    const SEMADDS_Types::SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::unregister_instance(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::unregister_instance_w_timestamp (
    const SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::write (
    const SEMADDS_Types::SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::write(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::write_w_timestamp (
    const SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::dispose (
    const SEMADDS_Types::SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::dispose(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::dispose_w_timestamp (
    const SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::writedispose (
    const SEMADDS_Types::SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::writedispose(&instance_data, handle);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::writedispose_w_timestamp (
    const SemaEApi & instance_data,
    ::DDS::InstanceHandle_t handle,
    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::writedispose_w_timestamp(&instance_data, handle, source_timestamp);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataWriter_impl::get_key_value (
    SemaEApi & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::SemaEApiDataWriter_impl::lookup_instance (
    const SEMADDS_Types::SemaEApi & instance_data) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataWriter_impl::lookup_instance(&instance_data);
}

// DDS SEMADDS_Types::SemaEApi DataReader_impl Object Body
SEMADDS_Types::SemaEApiDataReader_impl::SemaEApiDataReader_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::SemaEApiDataReader_impl::~SemaEApiDataReader_impl ()
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::init (
    DDS::OpenSplice::Subscriber *subscriber,
    const DDS::DataReaderQos &qos,
    DDS::OpenSplice::TopicDescription *a_topic,
    const char *name,
    DDS::OpenSplice::cxxCopyIn copyIn,
    DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataReader_impl::nlReq_init(
            subscriber, qos, a_topic, name, copyIn, copyOut,
            this->dataSeqAlloc, this->dataSeqLength, this->dataSeqGetBuffer, this->dataSeqCopyOut);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status = DDS::RETCODE_OK;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read_next_sample (
    SEMADDS_Types::SemaEApi & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::read_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take_next_sample (
    SEMADDS_Types::SemaEApi & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::take_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read_next_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take_next_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::read_next_instance_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::take_next_instance_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReader_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::return_loan (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t result = ::DDS::RETCODE_OK;

    result = this->write_lock ();
    if (result == DDS::RETCODE_OK) {
        if ( received_data.length() > 0 ) {
            if (received_data.length() == info_seq.length() &&
                received_data.release() == info_seq.release() ) {
                if (!received_data.release()) {
                    result = DDS::OpenSplice::FooDataReader_impl::wlReq_return_loan( received_data.get_buffer(),
                                                                                     info_seq.get_buffer() );
                    if ( result == ::DDS::RETCODE_OK ) {
                        if ( !received_data.release() ) {
                            SEMADDS_Types::SemaEApiSeq::freebuf( received_data.get_buffer(false) );
                            received_data.replace(0, 0, NULL, false);
                            ::DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                            info_seq.replace(0, 0, NULL, false);
                        }
                    }
                }
            } else {
                result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
        this->unlock();
    }
    return result;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::get_key_value (
    SEMADDS_Types::SemaEApi & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::SemaEApiDataReader_impl::lookup_instance (
    const SEMADDS_Types::SemaEApi & instance) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReader_impl::lookup_instance(&instance);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples)
{
    if ((max_samples < 0) && (max_samples != DDS::LENGTH_UNLIMITED)) {
        return DDS::RETCODE_BAD_PARAMETER;
    }

    /* Rule 1 : The values of len, max_len, and owns
     * for the two collections must be identical.
     */
    if ((received_data.length()  != info_seq.length())  ||
        (received_data.maximum() != info_seq.maximum()) ||
        (received_data.release() != info_seq.release()))
    {
        return DDS::RETCODE_PRECONDITION_NOT_MET;
    }

    /* Rule 4: If the input max_len>0 and the input owns==FALSE,
     * then the read operation will fail.
     */
    if ((info_seq.maximum() > 0) &&
        (info_seq.release() == false))
    {
        return DDS::RETCODE_PRECONDITION_NOT_MET;
    }

    /* Rule 5: If input max_len>0 and the input owns==TRUE,
     * then the read operation will...
     */
    if (info_seq.maximum() > 0) { /* owns is true, because of rule 4. */
        /* Rule 5a: If max_samples = LENGTH_UNLIMITED,
         * then at most max_len values will be copied.
         * Rule 5b: If max_samples <= max_len,
         * then at most max_samples values will be copied.
         */
        /* Rule 5c: If max_samples > max_len,
         * then the read operation will fail.
         */
        if ((max_samples != DDS::LENGTH_UNLIMITED) &&
            ((DDS::ULong)max_samples > info_seq.maximum())) {
            return DDS::RETCODE_PRECONDITION_NOT_MET;
        }
    }

    if ((max_samples == 0) ||
        ((info_seq.maximum() == 0) && (info_seq.release()))) {
        return DDS::RETCODE_NO_DATA;
    }

    return DDS::RETCODE_OK;
}

void *
SEMADDS_Types::SemaEApiDataReader_impl::dataSeqAlloc (
    void * received_data,
    DDS::ULong len)
{
    SEMADDS_Types::SemaEApiSeq *data_seq = reinterpret_cast<SEMADDS_Types::SemaEApiSeq *>(received_data);
    data_seq->replace(len, len, data_seq->allocbuf(len), false);
    return data_seq->get_buffer();
}

void *
SEMADDS_Types::SemaEApiDataReader_impl::dataSeqGetBuffer (
    void * received_data,
    DDS::ULong index)
{
	SEMADDS_Types::SemaEApiSeq *data_seq = reinterpret_cast<SEMADDS_Types::SemaEApiSeq *>(received_data);
	return &((*data_seq)[index]);
}

void
SEMADDS_Types::SemaEApiDataReader_impl::dataSeqLength (
    void * received_data,
    DDS::ULong len)
{
    SEMADDS_Types::SemaEApiSeq *data_seq = reinterpret_cast<SEMADDS_Types::SemaEApiSeq *>(received_data);
    data_seq->length(len);
}

void
SEMADDS_Types::SemaEApiDataReader_impl::dataSeqCopyOut (
    const void * from,
    void * to)
{
    SEMADDS_Types::SemaEApi *data = reinterpret_cast<SEMADDS_Types::SemaEApi *>(to);
    __SEMADDS_Types_SemaEApi__copyOut(from, data);
}

void
SEMADDS_Types::SemaEApiDataReader_impl::copyDataOut (
    const void * from,
    void * to)
{
    SEMADDS_Types::SemaEApi *data = reinterpret_cast<SEMADDS_Types::SemaEApi *>(to);
    __SEMADDS_Types_SemaEApi__copyOut(from, data);
}


// DDS SEMADDS_Types::SemaEApi DataReaderView_impl Object Body
SEMADDS_Types::SemaEApiDataReaderView_impl::SemaEApiDataReaderView_impl ()
{
    // Parent constructor takes care of everything.
}

SEMADDS_Types::SemaEApiDataReaderView_impl::~SemaEApiDataReaderView_impl ()
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::init (
    DDS::OpenSplice::DataReader *reader,
    const char *name,
    const DDS::DataReaderViewQos &qos,
    DDS::OpenSplice::cxxCopyIn copyIn,
    DDS::OpenSplice::cxxCopyOut copyOut)
{
    return DDS::OpenSplice::FooDataReaderView_impl::nlReq_init(
            reader, name, qos, copyIn, copyOut, SEMADDS_Types::SemaEApiDataReader_impl::dataSeqAlloc,
            SEMADDS_Types::SemaEApiDataReader_impl::dataSeqLength);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take(&received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_w_condition(&received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read_next_sample (
    SEMADDS_Types::SemaEApi & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::read_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take_next_sample (
    SEMADDS_Types::SemaEApi & received_data,
    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::take_next_sample(&received_data, sample_info);
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read_next_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take_next_instance (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::SampleStateMask sample_states,
    ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_next_instance(&received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::read_next_instance_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::read_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::take_next_instance_w_condition (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq,
    ::DDS::Long max_samples,
    ::DDS::InstanceHandle_t a_handle,
    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t status;

    status = SEMADDS_Types::SemaEApiDataReader_impl::check_preconditions(received_data, info_seq, max_samples);
    if ( status == ::DDS::RETCODE_OK ) {
        status = DDS::OpenSplice::FooDataReaderView_impl::take_next_instance_w_condition(&received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::return_loan (
    SEMADDS_Types::SemaEApiSeq & received_data,
    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS
{
    ::DDS::ReturnCode_t result = ::DDS::RETCODE_OK;

    result = this->write_lock ();
    if (result == DDS::RETCODE_OK) {
        if ( received_data.length() > 0 ) {
            if (received_data.length() == info_seq.length() &&
                received_data.release() == info_seq.release() ) {
                if (!received_data.release()) {
                    result = DDS::OpenSplice::FooDataReaderView_impl::wlReq_return_loan( received_data.get_buffer(),
                                                           info_seq.get_buffer() );

                    if ( result == ::DDS::RETCODE_OK ) {
                        if ( !received_data.release() ) {
                            SEMADDS_Types::SemaEApiSeq::freebuf( received_data.get_buffer(false) );
                            received_data.replace(0, 0, NULL, false);
                            ::DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(false) );
                            info_seq.replace(0, 0, NULL, false);
                        }
                    } else if ( result == ::DDS::RETCODE_NO_DATA ) {
                        if ( received_data.release() ) {
                            result = ::DDS::RETCODE_OK;
                        } else {
                            result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
                        }
                    }
                }
            } else {
                result = ::DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
        this->unlock();
    }
    return result;
}

::DDS::ReturnCode_t
SEMADDS_Types::SemaEApiDataReaderView_impl::get_key_value (
    SEMADDS_Types::SemaEApi & key_holder,
    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::get_key_value(&key_holder, handle);
}

::DDS::InstanceHandle_t
SEMADDS_Types::SemaEApiDataReaderView_impl::lookup_instance (
    const SEMADDS_Types::SemaEApi & instance) THROW_ORB_EXCEPTIONS
{
    return DDS::OpenSplice::FooDataReaderView_impl::lookup_instance(&instance);
}
