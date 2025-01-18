#ifndef _APPLICATION_H
#define _APPLICATION_H

#ifdef DECEMBER_DLL
    #define DECEMBER_API __declspec(dllexport)
#else
    #define DECEMBER_API __declspec(dllimport)
#endif

#endif
