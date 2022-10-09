#include <benchmark/benchmark.h>
#define BENCHMARK_STATIC_DEFINE

// Alternatively, can add libraries using linker options.
#ifdef _WIN32
//#pragma comment ( lib, "Shlwapi.lib" )
#endif

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();