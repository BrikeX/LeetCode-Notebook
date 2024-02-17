/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    // return Recursion(n);
    return DP(n);
  }

 private:
  int Recursion(const int n) const;
  int DP(const int n) const;
};

int Solution::Recursion(const int n) const {
  if (n <= 0) {
    return 0;
  }
  if (1 == n) {
    return 1;
  }
  return Recursion(n - 1) + Recursion(n - 2);
}

int Solution::DP(const int n) const {
  if (n <= 0) {
    return 0;
  }
  if (1 == n) {
    return 1;
  }
  int f0 = 0;
  int f1 = 1;
  int fn = 0;
  for (int i = 2; i <= n; ++i) {
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
  }
  return fn;
}

// @lc code=end
