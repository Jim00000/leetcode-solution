#!/bin/bash

clang -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer solution.c main.c