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
//#include <stdlib.h>
//#include <cstdio>
//#include <time.h>
//#include <string.h>
//#include <pthread.h>
//#include <unistd.h>
//#include <errno.h>
//#include <ctype.h>
//#include <stdio.h>

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
PAL_API PAL_INT pal_print(PAL_CSTR p)
{
	printf("%s",p);
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
	PAL_HANDLE result = NULL;
	int err = pthread_create(pid, NULL, (void* (*)(void*))proutine, pparamter);
	if(err != 0)
	{
		pal_print("create thread error \n");
	}
	else
	{
		result = (PAL_HANDLE)pid;
	}
	return result;
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
	struct tm *tm;
	int l = 0;
	char buf[30], usec_buf[6];
	timespec_get(&ts, TIME_UTC);
	tm = localtime(&ts.tv_sec);
	strftime(buf, 30, "%Y/%m/%d %H:%M:%S", tm);
	strcat(buf, ".");
	int ms = (int) ts.tv_nsec / 1000000;
	sprintf(usec_buf, "%03d", ms);
	strcat(buf, usec_buf);
	if ((l = (int) strlen(buf)) < size)
	{
		strcpy(p, buf);
		return l;
	}
	return 0;

}

