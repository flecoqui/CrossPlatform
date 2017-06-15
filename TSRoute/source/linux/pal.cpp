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
#include <pal.h>
#include <cstdio>
#include <time.h>
PAL_API PAL_INT pal_print(PAL_CSTR p)
{
	puts(p);
	return 0;
}
PAL_API PAL_VOID pal_sleep(PAL_DWORD durationms)
{
	struct timespec tm;
	tm.tv_sec = durationms / 1000;
	tm.tv_nsec = (durationms % 1000)*1000000;
	nanosleep(&tm,NULL);
	return;
}
PAL_API PAL_HANDLE pal_createthread(PAL_ROUTINE proutine, PAL_VOID* pparamter, PAL_DWORD* pid)
{
	return 0;
}

