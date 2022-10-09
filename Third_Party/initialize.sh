#!/bin/bash
git submodule update --init

cd googletest
git checkout release-1.12.1
cmake -E make_directory "build"
cmake -E chdir "build" cmake ../
cmake --build "build" --config Release

cd ../benchmark
git checkout v1.7.0
git apply ../patch/benchmark_fix_unresolved_symbols_issue.patch
cmake -E make_directory "build"
cmake -E chdir "build" cmake -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ../
cmake --build "build" --config Release