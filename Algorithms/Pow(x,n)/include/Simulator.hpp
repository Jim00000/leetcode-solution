#pragma once

#include "ISimulator.hpp"

class Simulator : public leetcode::ISimulator
{
   public:
    virtual std::optional<double> simulate(double x, int n) override;
};