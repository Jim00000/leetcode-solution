#include <vector>
#include <algorithm>

/**
 * @brief solution of Remove Element
 * 
 * Time complexity: O(N)
 * Space complexity: O(1)
 */
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int hit = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == val) {
                std::swap(nums[i], nums[nums.size() - 1 - hit]);
                hit++;
            }
        }
        return nums.size() - hit;
    }
};