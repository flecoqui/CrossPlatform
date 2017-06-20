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
#include <iostream>
#include <string>
PAL_DWORD PAL_STDAPI thread(PAL_DWORD *p)
{
	PAL_DWORD count = *p;
	char Decbuffer[30];
	sprintf(&Decbuffer[0],"%lu", count);
	pal_print(Decbuffer);
	pal_print("Counter: ");
	sprintf(&Decbuffer[0], " - pointer: %p", p);
	pal_print(Decbuffer);
	pal_print("\n");

	char timebuffer[30];
	for (PAL_DWORD i = 0; i < *p; i++)
	{
		pal_print("Thread Wait 100ms at ");
		if (pal_gettickcountstring(&timebuffer[0], sizeof(timebuffer)) > 0)
			pal_print(timebuffer);
		pal_print("\n");
		pal_sleep(100);
		pal_print("Thread Wait done at ");
		if (pal_gettickcountstring(&timebuffer[0], sizeof(timebuffer)) > 0)
			pal_print(timebuffer);
		pal_print("\n");

	}
	*p = 0;
	count = *p;
	sprintf(&Decbuffer[0], "%lu", count);
	pal_print("Counter: ");
	pal_print(Decbuffer);
	sprintf(&Decbuffer[0], " - pointer: %p", p);
	pal_print(Decbuffer);
	pal_print("\n");
	return 0;
}
int main(void)
{
	char timebuffer[30];
	char Decbuffer[30];
	std::cout << "hello world" << std::endl;
	printf("Hello World\r\n");
	pal_print("Hello World\r\n");
	for (int i = 0; i < 10; i++)
	{
		pal_print("Wait 100ms at ");
		if (pal_gettickcountstring(&timebuffer[0], sizeof(timebuffer)) > 0)
			pal_print(timebuffer);
		pal_print("\n");
		pal_sleep(100);
		pal_print("Wait done at ");
		if (pal_gettickcountstring(&timebuffer[0], sizeof(timebuffer)) > 0)
			pal_print(timebuffer);
		pal_print("\n");

	}

	PAL_DWORD threadId = 0;
	PAL_DWORD param = 5;
	PAL_HANDLE h = pal_createthread((PAL_ROUTINE) thread,&param,&threadId);
	pal_print("CreateThread");
	if (h != NULL)
	{
		pal_print("Wait end of thread");
		while (param > 0)
		{
			sprintf(&Decbuffer[0], "%lu", param);
			pal_print("Main Counter: ");
			pal_print(Decbuffer);
			sprintf(&Decbuffer[0], " - pointer: %p", &param);
			pal_print(Decbuffer);
			pal_print("\n");
			pal_sleep(100);
		}
		sprintf(&Decbuffer[0], "%lu", param);
		pal_print("Main Counter: ");
		pal_print(Decbuffer);
		pal_print("\n");
		pal_print("Wait end of thread done");
	}
	return 0;
}
