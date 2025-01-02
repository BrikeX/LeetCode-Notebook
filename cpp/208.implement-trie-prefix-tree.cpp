/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

#include <cctype>
#include <string>
#include <vector>

class Trie {
 public:
  Trie() = default;
  ~Trie() {
    for (auto &trie_ptr : next_) {
      delete trie_ptr;
    }
  }

  void insert(std::string word) {
    auto node = this;
    for (const char ch : word) {
      if (!std::islower(ch)) {
        return;
      }
      const int idx = ch - 'a';
      if (!node->next_[idx]) {
        node->next_[idx] = new Trie();
      }
      node = node->next_[idx];
    }
    node->end_ = true;
  }

  bool search(std::string word) const {
    auto node = SearchPrefix(word);
    return node && node->end_;
  }

  bool startsWith(std::string prefix) const {
    return nullptr != SearchPrefix(prefix);
  }

 private:
  Trie const *SearchPrefix(const std::string &prefix) const {
    auto node = this;

    for (const char ch : prefix) {
      if (!std::islower(ch)) {
        return nullptr;
      }
      const int idx = ch - 'a';
      if (!node->next_[idx]) {
        return nullptr;
      }
      node = node->next_[idx];
    }
    return node;
  }

 private:
  bool end_ = false;
  std::vector<Trie *> next_{26, nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
