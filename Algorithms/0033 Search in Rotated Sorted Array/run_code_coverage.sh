#!/bin/bash
clang -O0 -fprofile-instr-generate -fcoverage-mapping -mllvm -runtime-counter-relocation solution.c main.c -o coverage.exe
./coverage.exe
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov show ./coverage.exe -instr-profile=default.profdata
rm coverage.exe default.profraw default.profdata