#include <vector>
#include <unordered_set>

/**
 * @brief solution of Contains Duplicate
 * 
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for(const auto& num : nums)
            set.emplace(num);
        return nums.size() != set.size();
    }
};