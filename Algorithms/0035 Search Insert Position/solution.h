#pragma once

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

#ifdef __cplusplus
extern "C" {
#endif
int searchInsert(int* nums, int numsSize, int target);
#ifdef __cplusplus
}
#endif