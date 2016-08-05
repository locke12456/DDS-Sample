#include "dds_rmi-lite.h"
#ifndef DDS_RMISPLTYPES_H
#define DDS_RMISPLTYPES_H



extern  void __DDS_RMI_Identification__copyIn(const void *from, void *to);

extern  void __DDS_RMI_Identification__copyOut(const void *_from, void *_to);
extern  void __DDS_RMI_Identification__copyOutSeq(void *_from[], void *_to, int n);

extern  void * __DDS_RMI_Identification__allocator();
extern  void __DDS_RMI_Identification__deallocator(void *p);


extern  void __DDS_RMI_Definition__copyIn(const void *from, void *to);

extern  void __DDS_RMI_Definition__copyOut(const void *_from, void *_to);
extern  void __DDS_RMI_Definition__copyOutSeq(void *_from[], void *_to, int n);

extern  void * __DDS_RMI_Definition__allocator();
extern  void __DDS_RMI_Definition__deallocator(void *p);


extern  void __DDS_RMI_Client_Identification__copyIn(const void *from, void *to);

extern  void __DDS_RMI_Client_Identification__copyOut(const void *_from, void *_to);
extern  void __DDS_RMI_Client_Identification__copyOutSeq(void *_from[], void *_to, int n);

extern  void * __DDS_RMI_Client_Identification__allocator();
extern  void __DDS_RMI_Client_Identification__deallocator(void *p);


extern  void __DDS_RMI_Request_Header__copyIn(const void *from, void *to);

extern  void __DDS_RMI_Request_Header__copyOut(const void *_from, void *_to);
extern  void __DDS_RMI_Request_Header__copyOutSeq(void *_from[], void *_to, int n);

extern  void * __DDS_RMI_Request_Header__allocator();
extern  void __DDS_RMI_Request_Header__deallocator(void *p);


#undef OS_API
#endif
