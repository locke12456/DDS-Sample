//----------------------------------------------------------------
//
//-- Filename: ils/logging/appendertree.h
//-- INTERNAL USE ONLY
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_LOGGING_APPENDERTREE_H_
#define ILS_LOGGING_APPENDERTREE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char name[MAX_APPENDER_NAME+1];
	int level;
	void *appender;
} APPENDER_LEVEL_NODE;

void appendertree_init(void);
int appendertree_add(const char *path, const char *appender, int level);
int appendertree_find( const char *path, APPENDER_LEVEL_NODE **appenders, int *level );

#ifdef __cplusplus
}
#endif

#endif /*APPENDERTREE_H_*/
