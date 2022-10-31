#!/bin/bash

clang -O3 -g -fsanitize=address,undefined -fno-omit-frame-pointer solution.c main.c