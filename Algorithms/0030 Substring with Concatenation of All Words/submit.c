#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode
{
    struct TrieNode *children[26];
    int childcnt;
    int hit;
    int count;
} TrieNode;

typedef struct
{
    TrieNode prefix;
} Trie;

typedef struct MyListNode
{
    union {
        TrieNode *data;
        int offset;
    };
    struct MyListNode *next;
} MyListNode;

typedef struct
{
    MyListNode *head;
    MyListNode *tail;
    int count;
} LinkedList;

TrieNode *createTrieNode()
{
    TrieNode *node = malloc(sizeof(TrieNode));
    memset(node, 0, sizeof(TrieNode));
    return node;
}

MyListNode *createListNode(TrieNode *trieNode)
{
    MyListNode *node = malloc(sizeof(MyListNode));
    node->data = trieNode;
    node->next = NULL;
    return node;
}

MyListNode *createListNodeForOffset(int offset)
{
    MyListNode *node = malloc(sizeof(MyListNode));
    node->offset = offset;
    node->next = NULL;
    return node;
}

LinkedList *createLinkedList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void LinkedListInsertTail(LinkedList *list, TrieNode *trieNode)
{
    if (list != NULL)
    {
        if (list->head == NULL)
        {
            list->head = createListNode(trieNode);
            list->tail = list->head;
        }
        else
        {
            list->tail->next = createListNode(trieNode);
            list->tail = list->tail->next;
        }
        list->count++;
    }
}

void LinkedListInsertOffsetToTail(LinkedList *list, int offset)
{
    if (list != NULL)
    {
        if (list->head == NULL)
        {
            list->head = createListNodeForOffset(offset);
            list->tail = list->head;
        }
        else
        {
            list->tail->next = createListNodeForOffset(offset);
            list->tail = list->tail->next;
        }
        list->count++;
    }
}

Trie *createTrie()
{
    Trie *trie = malloc(sizeof(Trie));
    memset(trie, 0, sizeof(Trie));
    return trie;
}

TrieNode *InsertTrie(Trie *trie, char *str)
{
    if (trie != NULL && str != NULL)
    {
        TrieNode *parent = &trie->prefix;

        while (*str != '\0')
        {
            const int idx = *str - 'a';
            TrieNode *child = parent->children[idx];
            if (child == NULL)
            {
                child = createTrieNode();
                parent->children[idx] = child;
                parent->childcnt++;
            }
            parent = child;
            str++;
        }

        parent->count++;        // record that this is the leaf node if count > 0
        if (parent->count == 1) // only return new node
            return parent;
    }

    return NULL;
}

void clearTrieNode(TrieNode **node)
{
    if (node != NULL && *node != NULL)
    {
        if ((*node)->childcnt > 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if ((*node)->children[i] != NULL)
                {
                    clearTrieNode(&(*node)->children[i]);
                }
            }
            free(*node);
            *node = NULL;
        }
        else
        {
            if ((*node)->count == 0)
                printf("[WARN] Invalid node \n");
            free(*node);
            *node = NULL;
        }
    }
}

void LinkedListClear(LinkedList **list)
{
    if (list != NULL && *list != NULL)
    {
        MyListNode *node = (*list)->head;
        while (node != NULL)
        {
            MyListNode *current = node;
            node = node->next;
            free(current);
        }
        free(*list);
        *list = NULL;
    }
}

void clearTrie(Trie **trie)
{
    if (trie != NULL && *trie != NULL)
    {
        for(int i = 0; i < 26; i++)
        {
            if((*trie)->prefix.children[i] != NULL)
            {
                clearTrieNode(&(*trie)->prefix.children[i]);
            }
        }
        free(*trie);
        *trie = NULL;
    }
}

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
    MyListNode *cur = list->head;
    while (cur != NULL)
    {
        if (cur->data->count != cur->data->hit)
            valid = false;
        cur->data->hit = 0;
        cur = cur->next;
    }
    return valid;
}

static int *convertListToArray(LinkedList *list)
{
    int *const result_array = malloc(list->count * sizeof(int));
    MyListNode *node = list->head;
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
                current->hit++;

            if (isAllWordsEncounteredAndClearHitCount(tracker))
                LinkedListInsertOffsetToTail(result, start);
        }
    }

    *returnSize = result->count;
    int *const array = convertListToArray(result);

    clearTrie(&trie);
    LinkedListClear(&tracker);
    LinkedListClear(&result);

    return array;
}