#pragma once

#include <optional>

namespace leetcode {

class ISimulator
{
   public:
    virtual ~ISimulator() {}

    virtual std::optional<double> simulate(double x, int n) = 0;
};
}  // namespace leetcode