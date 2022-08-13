#include <numeric>
#include <queue>
#include <vector>

struct heapnode
{
    int index;      
    int rating;     
    int left_neighbor_index;
    int left_neighbor_rating;
    int right_neighbor_index;
    int right_neighbor_rating;

    const bool operator>(const heapnode& rhs) const
    {
        return this->rating > rhs.rating;
    }

    const bool operator<(const heapnode& rhs) const
    {
        return this->rating < rhs.rating;
    }

};

/**
 * @brief solution of Candy
 * 
 * Time complexity : O(N * lgN)
 * Space complexity : O(N)
 */
class Solution {
    template<typename T>
    using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
public:
    int candy(std::vector<int>& ratings) {

        // handle case for single data
        if (ratings.size() == 1) {
            return 1;
        }

        int count = 0;
        std::vector<int> candies(ratings.size());
        minheap<heapnode> heap;

        for (size_t i = 0; i < ratings.size(); i++) {
            struct heapnode node;
            node.index = i;
            node.rating = ratings[i];
            if (i == 0) {
                node.left_neighbor_index = -1;
                node.left_neighbor_rating = std::numeric_limits<int>::max();
                node.right_neighbor_index = 1;
                node.right_neighbor_rating = ratings[1];
            }
            else if (i == ratings.size() - 1) {
                node.left_neighbor_index = ratings.size() - 2;
                node.left_neighbor_rating = ratings[ratings.size() - 2];
                node.right_neighbor_index = -1;
                node.right_neighbor_rating = std::numeric_limits<int>::max();
            }
            else {
                node.left_neighbor_index = i - 1;
                node.left_neighbor_rating = ratings[i - 1];
                node.right_neighbor_index = i + 1;
                node.right_neighbor_rating = ratings[i + 1];
            }
            heap.emplace(node);
        }

        while (not heap.empty()) {
            const heapnode& node = heap.top();
            
            // middle is the smallest
            if (node.rating < node.left_neighbor_rating && node.rating < node.right_neighbor_rating) {
                candies[node.index] = 1;
            }
            // larger than lhs but smaller than rhs
            else if (node.rating > node.left_neighbor_rating && node.rating < node.right_neighbor_rating) {
                candies[node.index] = candies[node.left_neighbor_index] + 1;
            }
            // smaller than lhs but larger than rhs
            else if (node.rating < node.left_neighbor_rating && node.rating > node.right_neighbor_rating) {
                candies[node.index] = candies[node.right_neighbor_index] + 1;
            }
            // middle is the largest
            else if(node.rating > node.left_neighbor_rating && node.rating > node.right_neighbor_rating) {
                candies[node.index] = std::max(candies[node.left_neighbor_index], candies[node.right_neighbor_index]) + 1;
            }
            // equal to lhs but larger than rhs
            else if (node.rating == node.left_neighbor_rating && node.rating > node.right_neighbor_rating) {
                candies[node.index] = candies[node.right_neighbor_index] + 1;
            }
            // larger than lhs but equal to rhs
            else if (node.rating > node.left_neighbor_rating && node.rating == node.right_neighbor_rating) {
                candies[node.index] = candies[node.left_neighbor_index] + 1;
            }
            else {
                candies[node.index] = 1;
            }

            // add count
            count += candies[node.index];

            // next iteration
            heap.pop();
        }

        return count;
    }
};