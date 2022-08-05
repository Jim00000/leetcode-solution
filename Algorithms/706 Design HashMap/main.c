#include "solution.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void hash_test()
{
    const size_t factor = 4;
    const size_t bucket_size = (size_t)pow(2, factor);
    int *const bucket_index = calloc(bucket_size, sizeof(int));

    for (int i = 0; i < 20; i++)
    {
        printf_s("%d -> bucket idx [%d]\n", i, hash(i, factor));
        bucket_index[hash(i, factor)]++;
    }

    for (int i = 0; i < bucket_size; i++)
    {
        printf_s("bucket_index[%d] %d \r\n", i, bucket_index[i]);
    }

    free(bucket_index);
}

void hashmap_test()
{
    MyHashMap *hashmap = myHashMapCreate();
    myHashMapPut(hashmap, 1, 100);
    myHashMapPut(hashmap, 2, 200);
    myHashMapPut(hashmap, 3, 300);
    myHashMapPut(hashmap, 4, 400);
    myHashMapPut(hashmap, 5, 500);
    printf_s("%d -> %d\n", 1, myHashMapGet(hashmap, 1));
    printf_s("%d -> %d\n", 2, myHashMapGet(hashmap, 2));
    printf_s("%d -> %d\n", 3, myHashMapGet(hashmap, 3));
    printf_s("%d -> %d\n", 4, myHashMapGet(hashmap, 4));
    printf_s("%d -> %d\n", 5, myHashMapGet(hashmap, 5));
    myHashMapPut(hashmap, 1, 1000);
    myHashMapPut(hashmap, 2, 2000);
    myHashMapPut(hashmap, 3, 3000);
    myHashMapPut(hashmap, 4, 4000);
    myHashMapPut(hashmap, 5, 5000);
    printf_s("%d -> %d\n", 1, myHashMapGet(hashmap, 1));
    printf_s("%d -> %d\n", 2, myHashMapGet(hashmap, 2));
    printf_s("%d -> %d\n", 3, myHashMapGet(hashmap, 3));
    printf_s("%d -> %d\n", 4, myHashMapGet(hashmap, 4));
    printf_s("%d -> %d\n", 5, myHashMapGet(hashmap, 5));
    myHashMapRemove(hashmap, 3);
    myHashMapRemove(hashmap, 4);
    printf_s("%d -> %d\n", 1, myHashMapGet(hashmap, 1));
    printf_s("%d -> %d\n", 2, myHashMapGet(hashmap, 2));
    printf_s("%d -> %d\n", 3, myHashMapGet(hashmap, 3));
    printf_s("%d -> %d\n", 4, myHashMapGet(hashmap, 4));
    printf_s("%d -> %d\n", 5, myHashMapGet(hashmap, 5));
    myHashMapPut(hashmap, 3, 9000);
    printf_s("%d -> %d\n", 1, myHashMapGet(hashmap, 1));
    printf_s("%d -> %d\n", 2, myHashMapGet(hashmap, 2));
    printf_s("%d -> %d\n", 3, myHashMapGet(hashmap, 3));
    printf_s("%d -> %d\n", 4, myHashMapGet(hashmap, 4));
    printf_s("%d -> %d\n", 5, myHashMapGet(hashmap, 5));
    myHashMapFree(hashmap);
}

void hashmap_test2()
{
    MyHashMap *hashmap = myHashMapCreate();

    const int count = 12;

    for(int i = 0; i < count; i++)
    {
        myHashMapPut(hashmap, i, i * 100);
    }

    myHashMapRemove(hashmap, 2);
    myHashMapRemove(hashmap, 3);
    myHashMapRemove(hashmap, 5);
    myHashMapRemove(hashmap, 7);
    myHashMapRemove(hashmap, 11);
    myHashMapPut(hashmap, 13, 13 * 100);
    myHashMapPut(hashmap, 14, 14 * 100);


    for(int i = 0; i < count; i++)
    {
        printf_s("%d -> %d\n", i, myHashMapGet(hashmap, i));
        fflush(stdout);
    }

    printf_s("entry count: %d\n", hashmap->entry_size);
    printf_s("bucket size: %d\n", hashmap->bucket_size);
    
    myHashMapFree(hashmap);
}

int main(int argc, char *argv[])
{
    // hashmap_test();
    hashmap_test2();
    return 0;
}