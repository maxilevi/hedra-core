#!/bin/bash
cd "$(dirname "$0")"

rm -r -dir --force ./cmake-build-x64-linux/
mkdir ./cmake-build-x64-linux/
cd ./cmake-build-x64-linux/
cmake ./..
cmake --build ./..

rm -r -dir --force ./cmake-build-x32-linux/
mkdir ./cmake-build-x32-linux/
cd ./cmake-build-x32-linux/
cmake ./..
cmake --build ./..