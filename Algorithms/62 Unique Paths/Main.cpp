#include <vector>

/**
 * @brief solution of Unique Paths
 * 
 * Time complexity : O(M * N)
 * Space complexity : O(M * N)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> board(m * n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                board[i * n + j] = board[(i - 1) * n + j] + board[i * n + (j - 1)];
            }
        }

        return board.back();
    }
};
