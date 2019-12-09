// C Header
#include <cassert>

// C++ header
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

#include "IListNodeBuilder.hpp"
#include "ListNode.hpp"
#include "Simulator.hpp"
#include "Solution.hpp"

using namespace ATN;

template <typename T,
          typename = std::enable_if_t<std::is_convertible_v<T, int>>>
class ListNodeBuilder : public IListNodeBuilder<std::initializer_list<T>>
{
   public:
    virtual ListNode* create(std::initializer_list<T>& list) override
    {
        const auto initializer = [] { return new ListNode(static_cast<T>(0)); };
        ListNode *header = initializer(), *current = header, *previous = header;
        for (const T digit : list) {
            previous = current;
            current->val = digit;
            current->next = initializer();
            current = current->next;
        }

        delete current;
        previous->next = nullptr;

        return header;
    }
};

const unsigned int toUInt32(ListNode* const l)
{
    if (l == nullptr) throw std::invalid_argument("ListNode is null");

    unsigned int digit = 1, result = 0;
    ListNode* head = l;

    while (head != nullptr) {
        result += digit * head->val;
        digit *= 10;
        head = head->next;
    }

    return result;
}

std::optional<uint32_t> Simulator::simulate(
    std::initializer_list<uint32_t>&& num1,
    std::initializer_list<uint32_t>&& num2)
{
    if (num1.size() == 0) throw std::invalid_argument("size of num1 is 0");
    if (num2.size() == 0) throw std::invalid_argument("size of num2 is 0");

    IListNodeBuilder<std::initializer_list<uint32_t>>* builder =
        new ListNodeBuilder<uint32_t>();

    ListNode* l1 = builder->create(num1);
    ListNode* l2 = builder->create(num2);

    Solution solver;
    ListNode* sum = solver.addTwoNumbers(l1, l2);

    return toUInt32(sum);
}