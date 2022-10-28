#!/bin/bash
clang -O0 -fprofile-instr-generate -fcoverage-mapping -mllvm -runtime-counter-relocation solution.c main.c -o longest_valid_parentheses_coverage.exe
./longest_valid_parentheses_coverage.exe
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov show ./longest_valid_parentheses_coverage.exe -instr-profile=default.profdata
rm longest_valid_parentheses_coverage.exe default.profraw default.profdata