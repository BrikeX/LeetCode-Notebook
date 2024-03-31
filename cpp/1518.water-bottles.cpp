/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int result = numBottles;
    int new_bottles = 0;
    int left_bottles = 0;
    while (numBottles >= numExchange) {
      new_bottles = numBottles / numExchange;
      left_bottles = numBottles % numExchange;
      result += new_bottles;
      numBottles = new_bottles + left_bottles;
    }
    return result;
  }
};
// @lc code=end
