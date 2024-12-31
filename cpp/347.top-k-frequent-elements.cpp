/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    if (k >= nums.size()) {
      return nums;
    }
    num_count_.reserve(nums.size());
    for (const int num : nums) {
      if (num_count_.cend() == num_count_.find(num)) {
        num_count_[num] = 1;
      } else {
        ++num_count_.at(num);
      }
    }
    PriorityQueue(k);

    // uni_nums_.reserve(num_count_.size());
    // for (const auto& [num, count] : num_count_) {
    //   uni_nums_.emplace_back(num);
    // }
    // QuickSelect(k, 0, uni_nums_.size() - 1);

    return result_;
  }

 private:
  void PriorityQueue(const int k);

  void QuickSelect(int k, int lo, int hi);
  int Partition(const int lo, const int hi);

 private:
  std::unordered_map<int, int> num_count_;
  std::vector<int> uni_nums_;
  std::vector<int> result_;
};

void Solution::PriorityQueue(const int k) {
  auto compare_count = [&](const std::pair<int, int>& lhs,
                           const std::pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(compare_count)>
      count_pq(compare_count);

  for (const auto& [num, count] : num_count_) {
    if (count_pq.size() < k) {
      count_pq.emplace(num, count);
    } else if (count_pq.top().second < count) {
      count_pq.pop();
      count_pq.emplace(num, count);
    }
  }
  result_.clear();
  result_.reserve(count_pq.size());
  while (!count_pq.empty()) {
    result_.emplace_back(count_pq.top().first);
    count_pq.pop();
  }
}

int Solution::Partition(const int lo, const int hi) {
  auto i = lo;
  auto j = hi + 1;
  const auto val = num_count_.at(uni_nums_[lo]);

  while (true) {
    while (num_count_.at(uni_nums_[++i]) > val) {
      if (hi == i) {
        break;
      }
    }
    while (num_count_.at(uni_nums_[--j]) < val) {
      if (lo == j) {
        break;
      }
    }
    if (i >= j) {
      break;
    }
    std::swap(uni_nums_[i], uni_nums_[j]);
  }
  std::swap(uni_nums_[lo], uni_nums_[j]);
  return j;
}

void Solution::QuickSelect(int k, int lo, int hi) {
  int pivot = num_count_.at(uni_nums_[lo]);
  int idx = lo;
  for (int i = lo + 1; i <= hi; ++i) {
    if (num_count_.at(uni_nums_[i]) >= pivot) {
      std::swap(uni_nums_[++idx], uni_nums_[i]);
    }
  }
  std::swap(uni_nums_[lo], uni_nums_[idx]);

  if (lo + k <= idx) {
    QuickSelect(k, lo, idx - 1);
  } else {
    for (auto i = lo; i <= idx; ++i) {
      result_.emplace_back(uni_nums_[i]);
    }
    const int new_k = k - (idx - lo + 1);
    if (new_k > 0) {
      QuickSelect(new_k, idx + 1, hi);
    }
  }
}
// @lc code=end
