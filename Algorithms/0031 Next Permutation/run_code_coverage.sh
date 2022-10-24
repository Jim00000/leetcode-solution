#!/bin/bash
clang -O0 -fprofile-instr-generate -fcoverage-mapping -mllvm -runtime-counter-relocation solution.c main.c -o next_permutation_coverage.exe
./next_permutation_coverage.exe
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov show ./next_permutation_coverage.exe -instr-profile=default.profdata
rm next_permutation_coverage.exe default.profraw default.profdata