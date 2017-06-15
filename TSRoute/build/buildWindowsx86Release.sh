#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/winx86 ]; then
mkdir ../Releases/winx86
fi
i686-w64-mingw32-g++  -I./../include -I./../include/linux -o ../Releases/winx86/tsroute.exe ../source/tsroute.cpp ./../source/linux/pal.cpp  -static-libstdc++ -static-libgcc


