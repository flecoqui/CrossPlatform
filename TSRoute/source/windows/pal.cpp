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

#include "pal.h"
#include <cstdio>
#include <time.h>
#include <string.h>

PAL_API PAL_INT pal_print(PAL_CSTR p)
{
	return printf(p);
	return 0;
}
PAL_API PAL_VOID pal_sleep(PAL_DWORD durationms)
{
	Sleep(durationms);
	return;
}
PAL_API PAL_HANDLE pal_createthread(PAL_ROUTINE proutine, PAL_VOID* pparamter, PAL_DWORD* pid)
{
	return 0;
}
PAL_API PAL_LONGLONG pal_gettickcount()
{
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	long long milliseconds = ts.tv_sec * 1000LL + ts.tv_sec / 1000;
	return milliseconds;
}

PAL_API PAL_INT pal_gettickcountstring(PAL_STR p, int size)
{
	struct timespec ts;
	struct tm tmbuf;
	int l = 0;
	char buf[30], usec_buf[6];
	timespec_get(&ts, TIME_UTC);
	localtime_s(&tmbuf,&ts.tv_sec);
	strftime(buf, 30, "%Y/%m/%d %H:%M:%S", &tmbuf);
	strcat_s(buf, ".");
	int ms = ts.tv_nsec / 1000000;
	sprintf_s(usec_buf, "%d", ms);
	strcat_s(buf, usec_buf);
	if ((l = (int)strlen(buf)) < size)
	{
		strcpy_s(p,size, buf);
		return l;
	}
	return 0;
}
