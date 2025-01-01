/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <deque>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    // PriorityQueue(nums, k);
    MonoQueue(nums, k);

    return result_;
  }

 private:
  void PriorityQueue(const std::vector<int> &nums, const int k);
  void MonoQueue(const std::vector<int> &nums, const int k);

 private:
  std::vector<int> result_;
};

void Solution::PriorityQueue(const std::vector<int> &nums, const int k) {
  auto compare_num = [](const std::pair<int, int> &lhs,
                        const std::pair<int, int> &rhs) {
    return lhs.first < rhs.first;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(compare_num)>
      ipq(compare_num);

  for (int i = 0; i < k; ++i) {
    ipq.emplace(nums[i], i);
  }
  result_.emplace_back(ipq.top().first);

  for (int i = k; i < nums.size(); ++i) {
    ipq.emplace(nums[i], i);
    while (ipq.top().second <= i - k) {
      ipq.pop();
    }
    result_.emplace_back(ipq.top().first);
  }
}

void Solution::MonoQueue(const std::vector<int> &nums, const int k) {
  std::deque<int> ideq;

  for (int i = 0; i < k; ++i) {
    while (!ideq.empty() && nums[i] >= nums[ideq.back()]) {
      ideq.pop_back();
    }
    ideq.push_back(i);
  }
  result_.emplace_back(nums[ideq.front()]);

  for (int i = k; i < nums.size(); ++i) {
    while (!ideq.empty() && nums[i] >= nums[ideq.back()]) {
      ideq.pop_back();
    }
    ideq.push_back(i);

    while (ideq.front() <= i - k) {
      ideq.pop_front();
    }
    result_.push_back(nums[ideq.front()]);
  }
}
// @lc code=end
