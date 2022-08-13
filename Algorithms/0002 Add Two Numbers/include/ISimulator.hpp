#pragma once

#include <cstdint>
#include <initializer_list>
#include <optional>

namespace leetcode {

class ISimulator
{
   public:
    virtual ~ISimulator() {}

    virtual std::optional<uint32_t> simulate(
        std::initializer_list<uint32_t>&& num1,
        std::initializer_list<uint32_t>&& num2) = 0;
};
}  // namespace leetcode