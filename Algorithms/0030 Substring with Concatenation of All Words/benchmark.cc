#include "solution.h"
#include <benchmark/benchmark.h>

static void BM_SampleFunction_1(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        // This code gets timed
        int returnSize;
        char *s = "barfoothefoobarman";
        char *words[] = {"foo", "bar"};
        constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
        int *indices = findSubstring(s, words, wordsSize, &returnSize);
    }
}

static void BM_SampleFunction_2(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        // This code gets timed
        int returnSize;
        char *s = "wordgoodgoodgoodbestword";
        char *words[] = {"word", "good", "best", "word"};
        constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
        int *indices = findSubstring(s, words, wordsSize, &returnSize);
    }
}

static void BM_SampleFunction_3(benchmark::State &state)
{
    // Perform setup here
    for (auto _ : state)
    {
        // This code gets timed
        int returnSize;
        char *s = "barfoofoobarthefoobarman";
        char *words[] = {"bar", "foo", "the"};
        constexpr int wordsSize = sizeof(words) / sizeof(words[0]);
        int *indices = findSubstring(s, words, wordsSize, &returnSize);
    }
}

// Register the function as a benchmark
BENCHMARK(BM_SampleFunction_1);
BENCHMARK(BM_SampleFunction_2);
BENCHMARK(BM_SampleFunction_3);
// Run the benchmark
BENCHMARK_MAIN();