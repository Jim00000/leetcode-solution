#include <vector>

/**
 * @brief solution of Find N Unique Integers Sum up to Zero
 * 
 * Time complexity : O(N)
 * Space complexity : O(N)
 */
class Solution {
public:
    std::vector<int> sumZero(int n) {
        
        std::vector<int> intset;
        
        // Is odd number ?
        if(n & 0x1 == 0x1) {
            intset.push_back(0);
            n--;
        }
        
        for(int i = 1; i <= (n >> 1); i++) {
                intset.push_back(i);
                intset.push_back(-i);
        }
                
        return intset;
    }
};