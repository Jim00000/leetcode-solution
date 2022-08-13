#include "solution.h"
#include <stdio.h>
#include <string.h>

static int getCharacterCount(char *str, int len)
{
    int ascii[128] = {0};
    int char_count = 0;
    for(int i = 0; i < len; i++)
    {
        if(ascii[str[i]] == 0)
        {
            char_count++;
            ascii[str[i]]++;
        }
    }
    return char_count;
}

int lengthOfLongestSubstring(char *s)
{
    const int len = strlen(s);
    const int char_count = getCharacterCount(s, len);

    if(char_count < 2)
        return char_count;

    int longest_substr_len = 0;
    int ascii[128];
    for(int start = 0; start < len; start++)
    {
        int substr_len = 0, end;
        memset(ascii, 0, 128 * sizeof(int));
        for(end = start; end < len; end++)
        {
            if(ascii[s[end]] == 0)
            {
                ascii[s[end]]++;
                substr_len++;
            }
            else
            {
                if(substr_len == char_count)
                    return substr_len;
                else // substr_len < char_count
                {
                    if(longest_substr_len < substr_len)
                        longest_substr_len = substr_len;
                }
                break;
            }
        }
        if(end == len && longest_substr_len < substr_len)
        {
            longest_substr_len = substr_len;
            break;
        }
    }

    return longest_substr_len;
}