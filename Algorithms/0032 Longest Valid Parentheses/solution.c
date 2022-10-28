#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

typedef struct
{
    int top;
    int *data;
    int size;
} Stack;

static Stack *createStack(const int capacity)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = capacity;
    stack->data = malloc(capacity * sizeof(int));
    return stack;
}

static void freeStack(Stack **stack)
{
    if (stack != NULL && *stack != NULL)
    {
        free((*stack)->data);
        free((*stack));
        *stack = NULL;
    }
}

int longestValidParentheses(char *s)
{
    if (*s == '\0')
        return 0;

    int slen = strlen(s);
    Stack *stack = createStack(slen + 1);

    stack->top++;
    stack->data[stack->top] = -1;

    int max = 0;
    char *base = s;
    while (*s != '\0')
    {
        int index = (int)(s - base);
        if (*s == '(')
        {
            stack->top++;
            stack->data[stack->top] = index;
        }
        else
        {
            if(stack->top != -1)
            {
                stack->top--;
            }
            if (stack->top == -1)
            {
                stack->top++;
                stack->data[stack->top] = index;
            }
            int len = (index - stack->data[stack->top]);
            max = max < len ? len : max;
        }
        s++;
    }

    freeStack(&stack);

    return max;
}