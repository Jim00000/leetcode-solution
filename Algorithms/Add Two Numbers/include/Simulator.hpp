#pragma once

#include "ISimulator.hpp"

class Simulator : public leetcode::ISimulator
{
   public:
    virtual std::optional<uint32_t> simulate(
        std::initializer_list<uint32_t>&& num1,
        std::initializer_list<uint32_t>&& num2) override;
};