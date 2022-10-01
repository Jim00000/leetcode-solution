#include "solution.h"
#include <stdint.h>

__attribute__((naked)) uint32_t __division_hardware_simulation(int32_t dividend, int32_t divisor)
{
    __asm__ volatile(
        /*  check special case (dividend = -2147483648; divisor = -1) */
        "cmpl   $0x80000000, %%ecx      \n"
        "jne    bypass_special_case     \n"
        "cmpl   $0xFFFFFFFF, %%edx      \n"
        "jne    bypass_special_case     \n"
        "movl   $2147483647, %%eax      \n"
        "retq                           \n"
        "bypass_special_case:           \n"
        // ---------------------------------------------------------------
        /* initialization */
        "movq   %%rcx, %%rax            \n"
        "movl   %%eax, %%ebx            \n"
        "negl   %%ebx                   \n"
        "test   %%eax, %%eax            \n"
        "cmovs  %%ebx, %%eax            \n"
        "shl    $1, %%rax               \n"
        // ---------------------------------------------------------------
        /* identify that quotient is positive or negatve */
        "movl   %%ecx, %%edi            \n" // Decide whether the quotient
        "andl   $0x80000000, %%edi      \n" // is negative. The result is
        "shr    $31, %%edi              \n" // stored in the r8d register
        "movl   %%edx, %%esi            \n"
        "andl   $0x80000000, %%esi      \n"
        "shr    $31, %%esi              \n"
        "xorl   %%esi, %%edi            \n"
        "movl   %%edi, %%r8d            \n" // %r8d hold negative flag
        // ---------------------------------------------------------------
        /* negate divisor if divisor is negative number */
        "mov    %%edx, %%ebx            \n"
        "negl   %%ebx                   \n"
        "test   %%esi, %%esi            \n"
        "cmovnz  %%ebx, %%edx           \n"
        // ---------------------------------------------------------------
        /* Division hardware simulation - calculating quotient & remainder */
        "movl   $32, %%ecx              \n"
        "process_division_iter:         \n"
        "movq   %%rax, %%rbx            \n"
        "shr    $32, %%rbx              \n"
        "subl   %%edx, %%ebx            \n"
        "js     negative_case           \n"
        "shl    $32, %%rbx              \n"
        "movl   %%eax, %%eax            \n" // clear upper 32 bits of %rax
        "orq    %%rbx, %%rax            \n"
        "shl    $1, %%rax               \n"
        "movl   %%eax, %%ebx            \n"
        "inc    %%ebx                   \n"
        "andq   $0xFFFFFFFFFFFF0000, %%rax  \n" // clear quotient but keep
                                                // remainder's value
        "orq    %%rbx, %%rax            \n"
        "jmp    cont_loop               \n"
        "negative_case:                 \n"
        "shl    $1, %%rax               \n"
        "cont_loop:                     \n"
        "loop   process_division_iter   \n"
        // ---------------------------------------------------------------
        /* Handle negative quotient */
        "movl   %%eax, %%edx            \n"
        "negl   %%edx                   \n"
        "dec    %%r8d                   \n"
        "cmovns %%edx, %%eax            \n"
        "retq                           \n"
        :
        :
        : "cc", "rdi", "rsi", "rax", "rcx");
}

int32_t divide(int32_t dividend, int32_t divisor)
{
    return __division_hardware_simulation(dividend, divisor);
}