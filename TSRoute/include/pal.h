//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#ifndef PAL_H
#define PAL_H 1
#include <pal_types.h>

#if defined (__WINDOWS__)
#include<targetver.h>
#endif
#ifdef __cplusplus
#define PAL_EXTERN extern "C"
#else
# define VLC_EXTERN extern
#endif

#if defined (__WINDOWS__) && defined (DLL_EXPORT)
# define PAL_EXPORT __declspec(dllexport)
#elif defined (__LINUX__)
# define PAL_EXPORT __attribute__((visibility("default")))
#else
# define PAL_EXPORT
#endif

#define PAL_API PAL_EXTERN PAL_EXPORT


PAL_API PAL_INT  pal_print(PAL_CSTR p);
PAL_API PAL_VOID pal_sleep(PAL_DWORD durationms);
PAL_API PAL_HANDLE pal_createthread(PAL_ROUTINE proutine, PAL_VOID* pparamter, PAL_DWORD* pid);

#endif

