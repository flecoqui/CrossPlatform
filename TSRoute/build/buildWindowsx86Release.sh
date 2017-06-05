#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/winx86 ]; then
mkdir ../Releases/winx86
fi
i686-w64-mingw32-g++ -o ../Releases/winx86/tsroute.exe ../src/tsroute.cpp -static-libstdc++ -static-libgcc


