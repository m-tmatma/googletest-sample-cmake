#!/bin/sh

if [ ! -e googletest ]; then
    git submodule init
    git submodule update
fi

DIR=build
if [ "$(uname)" == 'Darwin' ]; then
    CMAKE=/Applications/CMake.app/Contents/bin/cmake
elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
    CMAKE=cmake
else
    echo "Your platform ($(uname -a)) is not supported."
    exit 1
fi

rm -rf $DIR

mkdir $DIR
$CMAKE -B$DIR -H. || exit 1
$CMAKE --build $DIR -- VERBOSE=1     || exit 1

