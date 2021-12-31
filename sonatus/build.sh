#!/bin/sh

echo "Building...."

rm -rf build
mkdir build
cmake -B ./build
make -C ./build
