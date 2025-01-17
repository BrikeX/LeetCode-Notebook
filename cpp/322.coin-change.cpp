/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    const auto default_val = amount + 1;
    std::vector<int> dp_vec(amount + 1, default_val);
    dp_vec[0] = 0;

    for (const auto coin : coins) {
      for (auto v = coin; v <= amount; ++v) {
        dp_vec[v] = std::min(dp_vec[v], dp_vec[v - coin] + 1);
      }
    }
    return dp_vec.back() == default_val ? -1 : dp_vec.back();
  }
};
// @lc code=end
