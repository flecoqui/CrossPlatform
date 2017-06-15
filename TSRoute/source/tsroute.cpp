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

int main(void)
{
	std::cout << "hello world" << std::endl;
	printf("Hello World\r\n");
	pal_print("Hello World\r\n");
	pal_print("Wait 1000ms\r\n");
	pal_sleep(1000);
	pal_print("Wait done\r\n");
	// CreateThread(NULL,0,)
	return 0;
}
