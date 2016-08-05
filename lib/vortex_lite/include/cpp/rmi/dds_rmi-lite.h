/****************************************************************

  Generated by Vortex Lite IDL to C Translator
  File name: dds_rmi.h
  Source: dds_rmi.idl
  Generated: Fri May 06 16:26:55 BST 2016
  Vortex Lite: V2.0.4

*****************************************************************/

#include "dds.h"

#ifndef _DDSL_DDS_RMI_H_
#define _DDSL_DDS_RMI_H_


#ifdef __cplusplus
extern "C" {
#endif

#define DDS_RMI_Diffusion_Service -1


typedef struct DDS_RMI_Identification
{
  char * server_class;
  char * server_impl;
  int32_t server_instance;
} DDS_RMI_Identification;

extern const dds_topic_descriptor_t DDS_RMI_Identification_desc;

#define DDS_RMI_Identification__alloc() \
((DDS_RMI_Identification*) dds_alloc (sizeof (DDS_RMI_Identification)));

#define DDS_RMI_Identification_free(d,o) \
dds_sample_free ((d), &DDS_RMI_Identification_desc, (o))

typedef struct DDS_RMI_method_list
{
  uint32_t _maximum;
  uint32_t _length;
  char * (*_buffer);
  bool _release;
} DDS_RMI_method_list;

#define DDS_RMI_method_list__alloc() \
((DDS_RMI_method_list*) dds_alloc (sizeof (DDS_RMI_method_list)));

#define DDS_RMI_method_list_allocbuf(l) \
((char * (*)) dds_alloc ((l) * sizeof (char *)))


typedef struct DDS_RMI_Definition
{
  char * server_class;
  DDS_RMI_method_list server_api;
} DDS_RMI_Definition;

extern const dds_topic_descriptor_t DDS_RMI_Definition_desc;

#define DDS_RMI_Definition__alloc() \
((DDS_RMI_Definition*) dds_alloc (sizeof (DDS_RMI_Definition)));

#define DDS_RMI_Definition_free(d,o) \
dds_sample_free ((d), &DDS_RMI_Definition_desc, (o))


typedef struct DDS_RMI_Client_Identification
{
  char * client_impl;
  int32_t client_instance;
  uint32_t request_id;
} DDS_RMI_Client_Identification;



typedef struct DDS_RMI_Request_Header
{
  DDS_RMI_Identification service_id;
  DDS_RMI_Client_Identification client_id;
} DDS_RMI_Request_Header;




#ifdef __cplusplus
}
#endif
#endif /* _DDSL_DDS_RMI_H_ */