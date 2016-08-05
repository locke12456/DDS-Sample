//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/json.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef JSON_H_
#define JSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#define JSON_FALSE    0
#define JSON_TRUE     1
#define JSON_NULL     2
#define JSON_NUMBER   3
#define JSON_STRING   4
#define JSON_ARRAY    5
#define JSON_OBJECT   6
#define JSON_INTEGER   7

#define json_IsReference 256

typedef struct _JSON {
	struct _JSON *next,*prev;	
	struct _JSON *child;

	int type;

	char *valuestring;
	int valueint;
	unsigned int valueuint;
	double valuedouble;
	char *string;
	long long valuelonglong;
} JSON;

// Supply a block of JSON, and this returns a JSON object you can interrogate. Call json_Delete when finished.
UTIL_EXPORT JSON *json_Parse(const char *value);
// Render a JSON entity to text for transfer/storage. Free the char* when finished.
UTIL_EXPORT char  *json_Print(JSON *item);
// Render a JSON entity to text for transfer/storage without any formatting. Free the char* when finished.
UTIL_EXPORT char  *json_PrintUnformatted(JSON *item);
// Delete a JSON entity and all subentities.
UTIL_EXPORT void   json_Delete(JSON *c);

// Returns the number of items in an array (or object).
UTIL_EXPORT int	  json_GetArraySize(JSON *array);
// Retrieve item number "item" from array "array". Returns NULL if unsuccessful.
UTIL_EXPORT JSON *json_GetArrayItem(JSON *array,int item);
// Looping through the children of an object or array.
typedef void (*json_fefunc)(JSON *item,void *custom);
UTIL_EXPORT int	 json_ObjectForeach(JSON *object, json_fefunc func,void *custom);
// Get item "string" from object. Case insensitive.
UTIL_EXPORT JSON *json_GetObjectItem(JSON *object,const char *string);

UTIL_EXPORT const char   *json_GetObjectItemAsString(	JSON *object,const char *string);
UTIL_EXPORT int          *json_GetObjectItemAsInt(		JSON *object,const char *string);
UTIL_EXPORT long long    *json_GetObjectItemAsLongLong(	JSON *object, const char *string);
UTIL_EXPORT unsigned int *json_GetObjectItemAsUInt(		JSON *object,const char *string);
UTIL_EXPORT double       *json_GetObjectItemAsDouble(	JSON *object,const char *string);
UTIL_EXPORT int          *json_GetObjectItemAsBool(		JSON *object,const char *string);

UTIL_EXPORT const char   *json_GetArrayItemAsString(	JSON *object,int item);
UTIL_EXPORT int          *json_GetArrayItemAsInt(		JSON *object,int item);
UTIL_EXPORT long long    *json_GetArrayItemAsLongLong(	JSON *object, int item);
UTIL_EXPORT unsigned int *json_GetArrayItemAsUInt(		JSON *object,int item);
UTIL_EXPORT double       *json_GetArrayItemAsDouble(	JSON *object,int item);
UTIL_EXPORT int          *json_GetArrayItemAsBool(		JSON *object,int item);
	
// These calls create a JSON item of the appropriate type.
UTIL_EXPORT JSON *json_CreateNull();
UTIL_EXPORT JSON *json_CreateTrue();
UTIL_EXPORT JSON *json_CreateFalse();
UTIL_EXPORT JSON *json_CreateNumber(double num);
UTIL_EXPORT JSON *json_CreateInteger(long long num);
UTIL_EXPORT JSON *json_CreateString(const char *string);
UTIL_EXPORT JSON *json_CreateArray();
UTIL_EXPORT JSON *json_CreateObject();

// These utilities create an Array of count items.
UTIL_EXPORT JSON *json_CreateBoolArray(char *numbers,int count);
UTIL_EXPORT JSON *json_CreateIntArray(int *numbers,int count);
UTIL_EXPORT JSON *json_CreateLongLongArray(long long *numbers, int count);
UTIL_EXPORT JSON *json_CreateFloatArray(float *numbers,int count);
UTIL_EXPORT JSON *json_CreateDoubleArray(double *numbers,int count);
UTIL_EXPORT JSON *json_CreateStringArray(const char **strings,int count);

// Append item to the specified array/object.
UTIL_EXPORT void    json_AddItemToArray(JSON *array, JSON *item);
UTIL_EXPORT void    json_AddItemToObject(JSON *object,const char *string,JSON *item);
// Append reference to item to the specified array/object. Use this when you want to add an existing JSON to a new JSON, but don't want to corrupt your existing JSON.
UTIL_EXPORT void    json_AddItemReferenceToArray(JSON *array, JSON *item);
UTIL_EXPORT void    json_AddItemReferenceToObject(JSON *object,const char *string,JSON *item);

// Remove/Detatch items from Arrays/Objects.
UTIL_EXPORT JSON *json_DetachItemFromArray(JSON *array,int which);
UTIL_EXPORT void   json_DeleteItemFromArray(JSON *array,int which);
UTIL_EXPORT JSON *json_DetachItemFromObject(JSON *object,const char *string);
UTIL_EXPORT void   json_DeleteItemFromObject(JSON *object,const char *string);
	
// Update array items.
UTIL_EXPORT void json_ReplaceItemInArray(JSON *array,int which,JSON *newitem);
UTIL_EXPORT void json_ReplaceItemInObject(JSON *object,const char *string,JSON *newitem);

#define json_AddNullToObject(object,name)	json_AddItemToObject(object, name, json_CreateNull())
#define json_AddTrueToObject(object,name)	json_AddItemToObject(object, name, json_CreateTrue())
#define json_AddFalseToObject(object,name)	json_AddItemToObject(object, name, json_CreateFalse())
#define json_AddBoolToObject(object,name,v)	json_AddItemToObject(object, name, (v)?json_CreateTrue():json_CreateFalse())
#define json_AddNumberToObject(object,name,n)	json_AddItemToObject(object, name, json_CreateNumber(n))
#define json_AddStringToObject(object,name,s)	json_AddItemToObject(object, name, json_CreateString(s))
#define json_AddIntegerToObject(object,name,n)	json_AddItemToObject(object, name, json_CreateInteger(n))

#ifdef __cplusplus
}
#endif

/*
  Copyright (c) 2009 Dave Gamble
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#endif /*ILS_UTIL_json_H_*/
