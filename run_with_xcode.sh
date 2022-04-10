#!/usr/bin/env bash

script_path=`cd $(dirname $0);pwd`

mkdir -p $script_path/build

cd $script_path/build

cmake .. -G Xcode -DCMAKE_SKIP_RPATH=YES

open $script_path/build/XEngineMain.xcodeproj
