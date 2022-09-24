#include "solution.h"
#include <stdlib.h>
#include <stdbool.h>

int strStr(char *haystack, char *needle)
{
    const char *const original_haystack = haystack;
    const char *const original_needle = needle;
    const char first_char = *original_needle;
    while (*haystack != '\0')
    {
        if (*haystack == first_char)
        {
            char* haystack_next = haystack + 1;
            bool anchor = false;

            while (*needle != '\0' && *haystack != '\0' && *haystack == *needle)
            {
                needle++;
                haystack++;
                if(anchor == false && *haystack == first_char)
                {
                    haystack_next = haystack;
                    anchor = true;
                }
            }

            if(*haystack == '\0' && *needle != '\0')
            {
                return -1;
            }
            else if (*needle == '\0')
            {
                return (size_t)haystack - (size_t)original_haystack - (needle - original_needle);
            }
            else
            {
                needle = (char *)original_needle;
                haystack = haystack_next;
            }
        }
        else
        {
            haystack++;
        }
    }

    return -1;
}