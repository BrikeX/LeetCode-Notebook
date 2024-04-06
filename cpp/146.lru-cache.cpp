/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <cstddef>
#include <memory>
#include <unordered_map>

struct Node {
  Node() = default;
  ~Node() = default;
  Node(const int k, const int v) : key(k), value(v){};

  int key = 0;
  int value = 0;

  std::weak_ptr<Node> prev;
  std::shared_ptr<Node> next;
};

class LinkedHashMap {
 public:
  LinkedHashMap() = default;
  ~LinkedHashMap() = default;

 public:
  void insert(const int key, const int value);
  void remove(const int key);
  void remove(const std::shared_ptr<Node> &node);
  void clear();
  bool get(const int key, int *const value) const;

  std::size_t size() const { return key2node_map_.size(); }
  std::shared_ptr<Node> head() const { return head_; }
  std::shared_ptr<Node> tail() const { return tail_.lock(); }

 private:
  std::unordered_map<int, std::shared_ptr<Node>> key2node_map_;
  std::shared_ptr<Node> head_;
  std::weak_ptr<Node> tail_;
};

void LinkedHashMap::insert(const int key, const int value) {
  const auto it = key2node_map_.find(key);
  if (key2node_map_.cend() != it) {
    if (it->second) {
      it->second->value = value;
    } else {
      remove(key);
      insert(key, value);
    }
    return;
  }
  const auto new_node = std::make_shared<Node>(key, value);
  if (!head_) {
    head_ = new_node;
    tail_ = head_;
  } else if (tail_.lock()) {
    auto last_node = tail_.lock();
    last_node->next = new_node;
    new_node->prev = last_node;
    tail_ = new_node;
  } else {
    return;
  }
  key2node_map_[key] = new_node;
}

void LinkedHashMap::remove(const int key) {
  const auto it = key2node_map_.find(key);
  if (key2node_map_.cend() == it) {
    return;
  }
  if (!it->second) {
    key2node_map_.erase(it);
    return;
  }
  auto node = it->second;
  auto prev_node = node->prev.lock();
  auto next_node = node->next;

  if (prev_node) {
    prev_node->next = next_node;
  } else {
    head_ = next_node;
  }
  if (next_node) {
    next_node->prev =
        prev_node ? std::weak_ptr<Node>(prev_node) : std::weak_ptr<Node>();
  } else {
    tail_ = prev_node;
  }
  key2node_map_.erase(key);
}

void LinkedHashMap::remove(const std::shared_ptr<Node> &node) {
  if (!node) {
    return;
  }
  remove(node->key);
}

void LinkedHashMap::clear() {
  key2node_map_.clear();
  head_.reset();
  tail_.reset();
}

bool LinkedHashMap::get(const int key, int *const value) const {
  if (!value) {
    return false;
  }
  const auto it = key2node_map_.find(key);
  if (key2node_map_.cend() == it) {
    return false;
  }
  if (!it->second) {
    return false;
  }
  *value = it->second->value;

  return true;
}

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    int value = 0;
    if (linked_hash_map_.get(key, &value)) {
      linked_hash_map_.remove(key);
      linked_hash_map_.insert(key, value);
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (-1 != get(key)) {
      linked_hash_map_.remove(key);
      linked_hash_map_.insert(key, value);
      return;
    }
    linked_hash_map_.insert(key, value);

    if (linked_hash_map_.size() > static_cast<std::size_t>(capacity_)) {
      linked_hash_map_.remove(linked_hash_map_.head());
    }
  }

 private:
  const int capacity_;
  LinkedHashMap linked_hash_map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
