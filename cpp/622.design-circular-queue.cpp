/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
#include <vector>

class MyCircularQueue {
 public:
  MyCircularQueue(int k) {
    begin_ = 0;
    end_ = 0;
    capacity_ = k + 1;
    elements_.resize(capacity_, 0);
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    elements_[end_] = value;
    end_ = (end_ + 1) % capacity_;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    begin_ = (begin_ + 1) % capacity_;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return elements_[begin_];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return elements_[(end_ - 1 + capacity_) % capacity_];
  }

  bool isEmpty() { return begin_ == end_; }

  bool isFull() { return ((end_ + 1) % capacity_) == begin_; }

 private:
  int begin_ = 0;
  int end_ = 0;
  int capacity_ = 0;

  std::vector<int> elements_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
