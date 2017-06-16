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
#ifndef PAL_TYPES_H
#define PAL_TYPES_H 1

typedef unsigned long PAL_DWORD;
typedef void PAL_VOID;
typedef void* PAL_HANDLE;
typedef int PAL_INT;
typedef const char* PAL_CSTR;
typedef char* PAL_STR;
#if defined (__WINDOWS__) 
#define PAL_STDAPI __stdcall 
typedef  __int64 PAL_LONGLONG;
#elif defined (__LINUX__) 
#define PAL_STDAPI 
typedef  long long PAL_LONGLONG;
#else
#define PAL_STDAPI 
typedef long long PAL_LONGLONG ;
#endif

typedef PAL_DWORD(PAL_STDAPI *PAL_ROUTINE)(
	PAL_VOID* lp
	);
#endif

