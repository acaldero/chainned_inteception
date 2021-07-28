#!/bin/sh
set -x

echo "compile i-1 + i-2..."
gcc -Wall -g -shared -fPIC -o i-1.so i-1.c -ldl
gcc -Wall -g -shared -fPIC -o i-2.so i-2.c -ldl

echo "compile main..."
gcc -Wall -g -o main.o -c main.c
gcc -Wall -g -o main main.o

echo "execute main..."
LD_PRELOAD="./i-2.so:./i-1.so" ./main

echo "clean all..."
rm *.o *.so main

