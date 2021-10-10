# googletest-sample-cmake

|CI|Status|
|:---|:---|
|github actions|[![github actions](https://github.com/m-tmatma/googletest-sample-cmake/actions/workflows/cmake.yml/badge.svg)](https://github.com/m-tmatma/googletest-sample-cmake/actions/workflows/cmake.yml)|
|travis-ci|[![Build Status](https://travis-ci.org/m-tmatma/googletest-sample-cmake.svg?branch=master)](https://travis-ci.org/m-tmatma/googletest-sample-cmake)|

This is an example for using GoogleTest and cmake

## How to get this ##
    > git clone --recursive https://github.com/m-tmatma/googletest-sample-cmake.git

or

    > git clone https://github.com/m-tmatma/googletest-sample-cmake.git  
    > cd googletest-sample-cmake  
    > git submodule init  
    > git submodule update  

## How to generate projects for Visual Studio

    > cmake -G "Visual Studio 15 2017" -B build -S .

## How to generate projects for Xcode

    $ cmake -G "Xcode" -B build -S .

## How to build

    cmake --build build-gtest-cmake
    cmake --build build-gtest-cmake --config Debug   
    cmake --build build-gtest-cmake --config Release

# How to create CMakeLists.txt which is project file for cmake

## How to create Solution Folder

<pre><code># turn on solution folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# create solution folder
# the first parameter of set_target_properties is a project name
# the last parateter of set_target_properties is a solution folder name
set_target_properties(gmock       PROPERTIES FOLDER GoogleTest)
set_target_properties(gmock_main  PROPERTIES FOLDER GoogleTest)
set_target_properties(gtest       PROPERTIES FOLDER GoogleTest)
set_target_properties(gtest_main  PROPERTIES FOLDER GoogleTest)
set_target_properties(calc        PROPERTIES FOLDER library)
set_target_properties(gtest_exe   PROPERTIES FOLDER executable)
</code></pre>

## How to use static runtime with Visual Studio

see https://cmake.org/Wiki/CMake_FAQ#How_can_I_build_my_MSVC_application_with_a_static_runtime.3F

<pre><code>foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
   if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
   endif(${flag_var} MATCHES "/MD")
endforeach(flag_var)
</code></pre>

## How to set Startup Project with Visual Studio

<pre><code> # the last parameter of set_property is a project name which we want to set as the startup project
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "gtest_exe" )</code></pre>


