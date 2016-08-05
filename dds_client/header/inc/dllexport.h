
#ifndef libSemaDDS_EXPORT_H
#define libSemaDDS_EXPORT_H
#ifdef _WIN32
#ifdef libSemaDDS_BUILT_AS_STATIC
#  define libSemaDDS_EXPORT
#  define LIBSEMADDS_NO_EXPORT
#else
#  ifndef libSemaDDS_EXPORT
#    ifdef libSemaDDS_EXPORTS
/* We are building this library */
#      define libSemaDDS_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define libSemaDDS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIBSEMADDS_NO_EXPORT
#    define LIBSEMADDS_NO_EXPORT 
#  endif
#endif

#ifndef LIBSEMADDS_DEPRECATED
#  define LIBSEMADDS_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIBSEMADDS_DEPRECATED_EXPORT
#  define LIBSEMADDS_DEPRECATED_EXPORT libSemaDDS_EXPORT LIBSEMADDS_DEPRECATED
#endif

#ifndef LIBSEMADDS_DEPRECATED_NO_EXPORT
#  define LIBSEMADDS_DEPRECATED_NO_EXPORT LIBSEMADDS_NO_EXPORT LIBSEMADDS_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define LIBSEMADDS_NO_DEPRECATED
#endif
#else 
#  define libSemaDDS_EXPORT
#endif

#endif