#pragma once

#include <tuple>

#include "ListNode.hpp"

namespace ATN {

template <typename T>
class IListNodeBuilder
{
   public:
    virtual ~IListNodeBuilder() {}

    virtual ListNode* create(T& input) = 0;
};

}  // namespace ATN