#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/winx64 ]; then
mkdir ../Releases/winx64
fi
x86_64-w64-mingw32-g++ -o ../Releases/winx64/tsroute.exe ../src/tsroute.cpp -static-libstdc++ -static-libgcc


