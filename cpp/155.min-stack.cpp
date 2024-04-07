/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <algorithm>
#include <limits>
#include <stack>

class MinStack {
 public:
  MinStack() { min_istk_.push(std::numeric_limits<int>::max()); }

  void push(int val) {
    istk_.push(val);
    min_istk_.push(std::min(val, min_istk_.top()));
  }

  void pop() {
    istk_.pop();
    min_istk_.pop();
  }

  int top() { return istk_.top(); }

  int getMin() { return min_istk_.top(); }

 private:
  std::stack<int> istk_;
  std::stack<int> min_istk_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
