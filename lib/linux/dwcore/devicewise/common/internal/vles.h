//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/internal/vles.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_INTERNAL_VLES_H_
#define DW_COMMON_INTERNAL_VLES_H_

#ifdef __cplusplus
extern "C" {
#endif

int vles_encode_length( int value, char **buffer );
void vles_decode_length( char **buffer, int *value );
int vles_get_length(int size);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_INTERNAL_VLES_H_*/
