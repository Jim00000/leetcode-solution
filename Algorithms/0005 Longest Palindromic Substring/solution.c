#include "solution.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool checkPalindromic(char *str, int start, int end)
{
    if(end - start + 1 < 2)
        return true;
    char *ch = str + start, *rev_ch = str + end;
    while (ch < rev_ch)
    {
        if(*ch != *rev_ch)
            return false;
        ch++;
        rev_ch--;
    }

    return true;
}

char *longestPalindrome(char *s)
{
    const int length = strlen(s);
    
    if (length < 2)
        return s;

    int longest_length = 0;
    int longest_start = -1;

    for (int start = 0; start < length - longest_length; start++)
    {
        for (int end = length - 1; end > start; end--)
        {
            if ( (end - start + 1) >= longest_length)
            {
                if (checkPalindromic(s, start, end) == true)
                {
                    int length = end - start + 1;
                    if(length > longest_length)
                    {
                        longest_length = length;
                        longest_start = start;   
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    if(longest_length == 0)
        return &s[length - 1]; 
    s[longest_start + longest_length] = '\0';
    return s + longest_start;
}