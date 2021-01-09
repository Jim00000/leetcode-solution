#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Solution of 1436 Destination City
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 */
class Solution {
public:
    string destCity(vector<vector<string>>& paths) noexcept {
        std::unordered_map<std::string, int> map;
        for(const auto& path : paths) {
            map[path[0]] += 2;
            map[path[1]] += 1;
        }
        const std::string dest = std::find_if(map.cbegin(), map.cend(), [](const auto& p) {return p.second == 1; })->first;
        return dest;
    }
};