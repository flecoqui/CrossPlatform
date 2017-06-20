#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/winx64 ]; then
mkdir ../Releases/winx64
fi
x86_64-w64-mingw32-g++ -D__WINDOWS__ -I./../include -I./../include/windows -I"/mnt/c/Program Files (x86)/Windows Kits/10/Include/10.0.15063.0/shared" -o ../Releases/winx64/tsroute.exe ../source/tsroute.cpp ./../source/windows/pal.cpp  -static-libstdc++ -static-libgcc


