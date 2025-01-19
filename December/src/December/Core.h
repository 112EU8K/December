#ifndef _ENTRY_POINT_H
#define _ENTRYPOINT_H

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef DECEMBER_BUILD_DLL
        #define DECEMBER_API __declspec(dllexport)
    #else
        #define DECEMBER_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) && __GNUC__ >= 4
    #define DECEMBER_API __attribute__((visibility("default")))
#else
    #define DECEMBER_API
#endif


#endif // _ENTRY_POINT_H

