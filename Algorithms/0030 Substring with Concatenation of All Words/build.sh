#!/bin/bash
clang -O0 -g -fsanitize=undefined -fno-omit-frame-pointer solution.c common.c main.c -o a.exe
# clang -O0 -fsanitize=address -fno-omit-frame-pointer solution.c common.c main.c -o a.exe