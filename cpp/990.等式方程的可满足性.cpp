/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start

#include <string>
#include <vector>

class WeightedQuickUnionUF {
 public:
  WeightedQuickUnionUF(const int n);

  inline int count() const { return count_; }

  int Find(int p) const;
  bool Connected(const int p, const int q) const { return Find(p) == Find(q); }
  void Union(const int p, const int q);

 private:
  std::vector<int> id_;
  std::vector<int> sz_;
  int count_ = 0;
};

WeightedQuickUnionUF::WeightedQuickUnionUF(const int n) : count_(n) {
  id_.resize(n);
  sz_.resize(n);
  for (int i = 0; i < n; ++i) {
    id_[i] = i;
    sz_[i] = 1;
  }
}

int WeightedQuickUnionUF::Find(int p) const {
  while (p != id_[p]) {
    p = id_[p];
  }
  return p;
}

void WeightedQuickUnionUF::Union(const int p, const int q) {
  const int i = Find(p);
  const int j = Find(q);
  if (i == j) {
    return;
  }
  if (sz_[i] < sz_[j]) {
    id_[i] = j;
    sz_[j] += sz_[i];
  } else {
    id_[j] = i;
    sz_[i] += sz_[j];
  }
  --count_;
}

class Solution {
 public:
  bool equationsPossible(const std::vector<std::string> &equations) {
    // Union-Find
    WeightedQuickUnionUF uf(26);

    for (const auto &str : equations) {
      if ('=' == str[1]) {
        uf.Union(str[0] - 'a', str[3] - 'a');
      }
    }
    for (const auto &str : equations) {
      if ('!' == str[1] && uf.Connected(str[0] - 'a', str[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
