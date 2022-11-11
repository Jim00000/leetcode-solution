#pragma once

#ifdef __cplusplus
#include <iostream>
#include <vector>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#endif

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

#ifdef __cplusplus
extern "C" {
#endif
char ** letterCombinations(char * digits, int* returnSize);
#ifdef __cplusplus
}
#endif