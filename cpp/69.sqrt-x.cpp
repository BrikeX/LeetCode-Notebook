/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    int mid = 0;
    int result = 0;
    long long sqrt = 0;

    while (left <= right) {
      mid = left + (right - left) / 2;
      sqrt = static_cast<long long>(mid) * static_cast<long long>(mid);
      if (sqrt == x) {
        return mid;
      } else if (sqrt < x) {
        left = mid + 1;
        result = mid;
      } else {
        right = mid - 1;
      }
    }
    return result;
  }
};
// @lc code=end
