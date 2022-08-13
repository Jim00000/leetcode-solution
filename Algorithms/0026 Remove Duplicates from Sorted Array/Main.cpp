#include <vector>
#include <set>

/**
 * @brief solution of Remove Duplicates from Sorted Array
 * 
 * - Time complexity: depend on the constructor of std::set and std::vector.
 * - Space complexity: O(N)
 */
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> sets {nums.cbegin(), nums.cend()};
        std::vector<int> newnums {sets.cbegin(), sets.cend()};
        nums = std::move(newnums);
        return sets.size();
    }
};