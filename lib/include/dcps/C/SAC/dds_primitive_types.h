/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2011 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef DDS_PRIMITIVE_TYPES_H
#define DDS_PRIMITIVE_TYPES_H

#if defined (__cplusplus)
extern "C" {
#endif

typedef short int                           DDS_short;
typedef int                                 DDS_long;
typedef long long int                       DDS_long_long;
typedef unsigned short int                  DDS_unsigned_short;
typedef unsigned int                        DDS_unsigned_long;
typedef unsigned long long int              DDS_unsigned_long_long;
typedef float                               DDS_float;
typedef double                              DDS_double;
typedef long double                         DDS_long_double;
typedef char                                DDS_char;
typedef unsigned char                       DDS_octet;
typedef unsigned char                       DDS_boolean;
typedef DDS_char *                          DDS_string;
typedef void *                              DDS_Object;

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef NULL
#define NULL 0
#endif


#if defined (__cplusplus)
}
#endif

#endif /* DDS_PRIMITIVE_TYPES_H */
