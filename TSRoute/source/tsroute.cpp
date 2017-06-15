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

#include <cstdio>
#include <iostream>
#include <string>
#include <pal.h>
int main(void)
{
	std::cout << "hello world" << std::endl;
	printf("Hello World\r\n");
	pal_print("Hello World\r\n");
	return 0;
}
