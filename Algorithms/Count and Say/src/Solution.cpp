#include <stdexcept>
#include <type_traits>
#include <unordered_map>

#include "Solution.hpp"

using namespace leetcode;
using namespace std::string_literals;  // use string literals

const static std::tuple<char, size_t, std::string::const_iterator>
analyzeLeadingCharacterSequence(const std::string& str)
{
    // duplicate count;
    size_t duplicate = 0;
    // lead character
    char lead = str.at(0);
    // string iterator
    auto cit = str.cbegin();
    // check loop
    while (*cit == lead && cit != str.cend()) {
        duplicate++;
        cit++;
    }
    return std::make_tuple(lead, duplicate, cit);
}

const inline static std::string buildNumberFrequencyString(const char c,
                                                           const size_t n)
{
    return std::to_string(n) + std::string(1, c);
}

// Input  : number stream
// Return : Unidentified number stream which are not handled, two-number pair
// string output (The first one is frequency and the second one is the leading
// number)
template <typename T, typename = std::enable_if_t<std::is_convertible_v<
                          std::remove_reference_t<T>, std::string>>>
static std::pair<std::string, std::string> serialAnalysis(T&& stream)
{
    std::string stringstream = static_cast<std::string>(stream);
    const auto [lead, duplicate, it] =
        analyzeLeadingCharacterSequence(stringstream);
    std::string unhandled(it, stringstream.cend());
    std::string numFreqStr = buildNumberFrequencyString(lead, duplicate);
    return std::make_pair(unhandled, numFreqStr);
}

std::string Solution::countAndSay(int n)
{
    if (n <= 0)
        throw std::domain_error("first argument n must satisfy : 1 <= n <= 30");

    if (n == 1) return "1"s;

    std::string stream = countAndSay(n - 1);
    std::string result;

    while (stream.empty() == false) {
        std::string output;
        std::tie(stream, output) = serialAnalysis(stream);
        // Append the output
        result += output;
    }

    return result;
}