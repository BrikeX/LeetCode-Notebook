/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (less_q_.size() == non_less_q_.size()) {
      less_q_.push(num);
      non_less_q_.push(less_q_.top());
      less_q_.pop();
    } else {
      non_less_q_.push(num);
      less_q_.push(non_less_q_.top());
      non_less_q_.pop();
    }
  }

  double findMedian() {
    if (less_q_.size() == non_less_q_.size()) {
      return (less_q_.top() + non_less_q_.top()) / 2.0;
    } else {
      return non_less_q_.top();
    }
  }

 private:
  std::priority_queue<int> less_q_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> non_less_q_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
