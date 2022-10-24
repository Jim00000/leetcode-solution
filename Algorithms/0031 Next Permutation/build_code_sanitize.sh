#!/bin/bash

# clang -O0 -g -fsanitize=undefined -fno-omit-frame-pointer solution.c main.c -o next_permutation.exe
clang -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer solution.c main.c -o next_permutation.exe