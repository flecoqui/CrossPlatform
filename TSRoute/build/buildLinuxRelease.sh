#!/bin/bash
if [ ! -d ../Releases ]; then
mkdir ../Releases
fi
if [ ! -d ../Releases/linuxx64 ]; then
mkdir ../Releases/linuxx64
fi
g++ -o ./../Releases/linuxx64/tsroute ./../src/tsroute.cpp

