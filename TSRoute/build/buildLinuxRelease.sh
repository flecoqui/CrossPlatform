#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/linuxx64 ]; then
mkdir ../Releases/linuxx64
fi

g++ -I./../include -I./../include/linux -o ./../Releases/linuxx64/tsroute ./../source/tsroute.cpp ./../source/linux/pal.cpp 
