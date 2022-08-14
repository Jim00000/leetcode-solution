#include "solution.h"
#include <stdlib.h>
#include <string.h>

// __attribute__((naked)) size_t __strlen_impl(char* s)
// {
//     asm volatile(
//         ".intel_syntax noprefix            \n\t"
//         "push rbp                          \n\t"
//         "mov rbp, rsp                      \n\t"
//         "mov rdi, rcx                      \n\t"
//         "mov al, 0                         \n\t"
//         "repne scasb                       \n\t"
//         "mov rax, rcx                      \n\t"
//         "leave                             \n\t"
//         "ret                               \n\t"
//         // ".att_syntax noprefix              \n\t"
//         :
//         :
//         :);
// }

size_t __strlen_impl(char *s)
{
    size_t ret;
    __asm__ volatile("pushq %%rdi \n"
                     "pushq %%rax \n"
                     "pushq %%rcx \n"
                     "movq %1, %%rdi \n"
                     "movb $0, %%al \n"
                     "repne scasb \n"
                     "movq %%rcx, %0 \n"
                     "popq %%rcx \n"
                     "popq %%rax \n"
                     "popq %%rdi \n"
                     : "=&d"(ret)
                     : "r"(s)
                     : "memory");
    return ret;
}

__attribute__((always_inline)) inline static size_t __strlen(char *s)
{
    const size_t base = (size_t)s;
    const size_t string_tail = __strlen_impl(s);
    return base - string_tail - 1;
}

char *convert(char *s, int numRows)
{
    if (numRows == 1)
        return s;
    const int len = strlen(s);
    char *zigzag = malloc((len + 1) * sizeof(char));
    int zigzag_ptr = 0;

    for (int row = 0; row < numRows; row++)
    {
        const int stride = (numRows - 1) * 2;
        const int step[2] = {(stride - 2 * row == 0) ? stride : stride - 2 * row,
                             (stride - step[0] == 0) ? stride : stride - step[0]};
        int idx = row;
        int selector = 0;
        while (idx < len)
        {
            zigzag[zigzag_ptr++] = s[idx];
            idx += step[selector];
            selector = (selector + 1) & 0x1;
        }
    }
    zigzag[zigzag_ptr] = '\0';

    return zigzag;
}