#include "solution.h"
#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void appendString(LinkedList *list, Trie *trie, char *string)
{
    if (list != NULL && trie != NULL)
    {
        TrieNode *leaf = InsertTrie(trie, string);
        if (leaf != NULL)
            LinkedListInsertTail(list, leaf);
    }
}

static bool isAllWordsEncounteredAndClearHitCount(LinkedList *list)
{
    bool valid = true;
    ListNode *cur = list->head;
    while (cur != NULL)
    {
        if (cur->data->count != cur->data->hit)
            valid = false;
        cur->data->hit = 0;
        cur = cur->next;
    }
    return valid;
}

static void dumpLeafTracker(LinkedList *list)
{
    printf("Dump leaf tracker:\n");
    ListNode *cur = list->head;
    while (cur != NULL)
    {
        printf("count %d hit %d\n", cur->data->count, cur->data->hit);
        cur = cur->next;
    }
}

static int *convertListToArray(LinkedList *list)
{
    int *const result_array = malloc(list->count * sizeof(int));
    ListNode *node = list->head;
    for (int i = 0; i < list->count; i++)
    {
        result_array[i] = node->offset;
        node = node->next;
    }

    return result_array;
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    LinkedList *tracker = createLinkedList();
    LinkedList *result = createLinkedList();
    Trie *trie = createTrie();
    int concated_word_length = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        appendString(tracker, trie, words[i]);
        concated_word_length += strlen(words[i]);
    }

    const int slen = strlen(s);
    TrieNode *root = &trie->prefix;
    TrieNode *current = root;

    for (int i = 0; i < slen; i++)
        printf("%2d %c\n", i, *(s + i));

    for (int start = 0; start <= slen - concated_word_length; start++)
    {
        const int idx = *(s + start) - 'a';
        if (root->children[idx] != NULL)
        {
            char *str = s + start;
            TrieNode *current = root;
            int footprint = 0;
            while (*str != '\0' && footprint < concated_word_length)
            {
                const int idx = *str - 'a';
                TrieNode *parent = current;
                current = current->children[idx];
                if (current == NULL)
                {
                    if (parent->count > 0)
                    {
                        parent->hit++;
                    }
                    current = root->children[idx];
                    if (current == NULL)
                        current = root;
                }
                str++;
                footprint++;
            }

            // check last character
            if (current->count > 0)
            {
                current->hit++;
            }

            // dumpLeafTracker(tracker);

            if (isAllWordsEncounteredAndClearHitCount(tracker))
            {
                printf("Find offset:%d\n", start);
                LinkedListInsertOffsetToTail(result, start);
            }
        }
    }

    *returnSize = result->count;
    int* const array = convertListToArray(result);

    clearTrie(&trie);
    LinkedListClear(&tracker);
    LinkedListClear(&result);
    return array;
}