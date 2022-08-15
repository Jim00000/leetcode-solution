#include "solution.h"
#include <stdlib.h>
#include <string.h>

enum
{
    NONE,
    PARENTHESES, // ()
    BRACKETS,    // []
    BRACES       // {}
};

typedef struct
{
    int *data;
    int size;
    int top;
} Stack;

static Stack *stackCreate(const int size)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->data = calloc(size, sizeof(int));
    stack->size = size;
    stack->top = -1; // empty
    return stack;
}

__attribute__((always_inline)) inline static void handleParenthesesProduce(Stack *stack, const int mark)
{
    stack->top++;
    stack->data[stack->top] = mark;
}

__attribute__((always_inline)) inline static bool handleParenthesesConsume(Stack *stack, const int mark)
{
    if(stack->top < 0)
        return false;
    
    if (stack->data[stack->top] != mark)
    {
        return false;
    }
    else
    {
        stack->data[stack->top] = NONE;
        stack->top--;
        return true;
    }
}

bool isValid(char *s)
{
    Stack *stack = stackCreate(strlen(s) + 4);
    while (*s != '\0')
    {
        switch (*s)
        {
        case '(':
            handleParenthesesProduce(stack, PARENTHESES);
            break;
        case ')':
            if (handleParenthesesConsume(stack, PARENTHESES) == false)
                return false;
            break;
        case '[':
            handleParenthesesProduce(stack, BRACKETS);
            break;
        case ']':
            if (handleParenthesesConsume(stack, BRACKETS) == false)
                return false;
            break;
        case '{':
            handleParenthesesProduce(stack, BRACES);
            break;
        case '}':
            if (handleParenthesesConsume(stack, BRACES) == false)
                return false;
            break;
        default:
            break;
        }
        s++;
    }

    const int top = stack->top;
    free(stack->data);
    free(stack);
    return top == -1 ? true : false;
}