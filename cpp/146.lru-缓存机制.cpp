/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        // 哈希链表
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!hash_map.count(key))
        {
            return -1;
        }
        
        auto kv_pair = *hash_map[key];

        cache.erase(hash_map[key]);

        cache.push_front(kv_pair);

        hash_map[key] = cache.begin();

        return kv_pair.second;
    }
    
    void put(int key, int value) {
        if (!hash_map.count(key))
        {
            if (cache.size() == capacity)
            {
                hash_map.erase(cache.back().first);

                cache.pop_back();
            }
        }
        else
        {
            cache.erase(hash_map[key]);
        }
        
        cache.push_front({key, value});

        hash_map[key] = cache.begin();
    }

private:
    int capacity;

    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> hash_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

