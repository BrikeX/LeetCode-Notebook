/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
#include <cstdlib>
#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight(std::vector<int>& stones) {
    if (1U == stones.size()) {
      return stones.front();
    }
    std::priority_queue<int> stone_pq;
    for (const auto weight : stones) {
      stone_pq.emplace(weight);
    }
    while (!stone_pq.empty()) {
      const auto lhs_stone = stone_pq.top();
      stone_pq.pop();
      if (stone_pq.empty()) {
        return lhs_stone;
      }
      const auto rhs_stone = stone_pq.top();
      stone_pq.pop();
      if (lhs_stone == rhs_stone) {
        continue;
      }
      stone_pq.emplace(std::abs(lhs_stone - rhs_stone));
    }
    return 0;
  }
};
// @lc code=end
