#pragma once

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#ifdef __cplusplus
extern "C" {
#endif
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize);
#ifdef __cplusplus
}
#endif