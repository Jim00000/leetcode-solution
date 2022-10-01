__attribute__((naked)) int32_t divide(int32_t dividend, int32_t divisor)
{
    __asm__ volatile(
        /*  check special case (dividend = -2147483648; divisor = -1) */
        "pushq  %%rbx                   \n"
        "pushq  %%rcx                   \n"
        "pushq  %%rdx                   \n"
        "pushq  %%r8                    \n"
        "cmpl   $0x80000000, %%edi      \n"
        "jne    bypass_special_case     \n"
        "cmpl   $0xFFFFFFFF, %%esi      \n"
        "jne    bypass_special_case     \n"
        "movl   $2147483647, %%eax      \n"
        "popq   %%r8                    \n"
        "popq   %%rdx                   \n"
        "popq   %%rcx                   \n"
        "popq   %%rbx                   \n"
        "retq                           \n"
        "bypass_special_case:           \n"
        // ---------------------------------------------------------------
        /* initialization */
        "movq   %%rdi, %%rax            \n"
        "movl   %%eax, %%ebx            \n"
        "negl   %%ebx                   \n"
        "test   %%eax, %%eax            \n"
        "cmovs  %%ebx, %%eax            \n"
        "shl    $1, %%rax               \n"
        // ---------------------------------------------------------------
        /* identify that quotient is positive or negatve */
        "movl   %%edi, %%ecx            \n" // Decide whether the quotient
        "andl   $0x80000000, %%ecx      \n" // is negative. The result is
        "shr    $31, %%ecx              \n" // stored in the r8d register
        "movl   %%esi, %%edx            \n"
        "andl   $0x80000000, %%edx      \n"
        "shr    $31, %%edx              \n"
        "xorl   %%edx, %%ecx            \n"
        "movl   %%ecx, %%r8d            \n" // %r8d hold negative flag
        // ---------------------------------------------------------------
        /* negate divisor if divisor is negative number */
        "mov    %%esi, %%ebx            \n"
        "negl   %%ebx                   \n"
        "test   %%edx, %%edx            \n"
        "cmovnz  %%ebx, %%esi           \n"
        // ---------------------------------------------------------------
        /* Division hardware simulation - calculating quotient & remainder */
        "movl   $32, %%ecx              \n"
        "process_division_iter:         \n"
        "movq   %%rax, %%rbx            \n"
        "shr    $32, %%rbx              \n"
        "subl   %%esi, %%ebx            \n"
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
        "popq   %%r8                    \n"
        "popq   %%rdx                   \n"
        "popq   %%rcx                   \n"
        "popq   %%rbx                   \n"
        "retq                           \n"
        :
        :
        : "cc", "rdi", "rsi", "rax", "rcx", "rbx", "rdx", "r8");
}