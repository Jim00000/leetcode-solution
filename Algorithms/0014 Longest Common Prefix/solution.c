#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  __string_compare(char *str1, char *str2)
 *
 *  Arguments: 
 *      str1:   first string
 *      str2:   second string
 *  Return:
 *      0: means both strings are same
 *  not 0: means both strings are different. The value presents the position of 
 *         first character is different. (1-based indexing)
 */
// __attribute__((naked)) int __string_compare(char *str1, char *str2, int len)
// {
//     __asm__ volatile (
//         /* instructions */
//         "movq   %%rcx, %%rdi    \n"
//         "movq   %%rdx, %%rsi    \n"
//         "movq   %%r8, %%rcx     \n"
//         "repe   cmpsb           \n"
//         "jne mismatch           \n"
//         "movq   %%rcx, %%rax    \n"
//         "retq                   \n"
//         "mismatch:              \n"
//         "movq   %%r8, %%rax     \n"
//         "subq   %%rcx, %%rax    \n"
//         "retq                   \n"
//         : 
//         :
//         : "cc", "rdi", "rsi", "rax", "rcx");
// }

__attribute__((naked)) int __string_compare(char *str1, char *str2, int len)
{
    __asm__ volatile (
        /* instructions */
        "movq   %%rcx, %%rdi    \n"
        "movq   %%rdx, %%rsi    \n"
        "movq   %%r8, %%rcx     \n"
        "repe   cmpsb           \n"
        "jne mismatch           \n"
        "movq   %%r8, %%rax     \n"
        "retq                   \n"
        "mismatch:              \n"
        "movq   %%r8, %%rax     \n"
        "subq   %%rcx, %%rax    \n"
        "xorq   %%rcx, %%rcx \n"
        "decq   %%rax           \n"
        "cmovs  %%rcx, %%rax \n"
        "retq                   \n"
        : 
        :
        : "cc", "rdi", "rsi", "rax", "rcx");
}

__attribute__((naked)) int __strlen(char *str)
{
    __asm__ volatile(
        /* instructions */
        "movq   %%rcx, %%rbx    \n"
        "movq   %%rcx, %%rdi    \n"
        "movb   $0,    %%al     \n"
        "repne  scasb           \n"
        "subq   %%rcx, %%rbx    \n"
        "decq   %%rbx           \n"
        "movq   %%rbx, %%rax    \n"
        "retq                   \n"
        : /* no output */
        : /* no input */
        : "cc", "rbx", "rcx", "rdi");
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    if(strsSize == 1)
        return strs[0];
    
    int mininal = __strlen(strs[0]);

    for(int i = 1; i < strsSize && mininal > 0; i++)
        mininal = __string_compare(strs[0], strs[i], mininal);

    char* prefix = calloc(mininal + 1, sizeof(char));
    memcpy(prefix, strs[0], mininal);
    return prefix;
}