/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class Node
{
public:
    int key, val, freq;

    Node(int _key, int _val, int _freq): key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        // 哈希链表
        this->capacity = capacity;

        freq_min = 0;
    }
    
    int get(int key) {
        if (capacity <= 0)
        {
            return -1;
        }
        
        auto it = key_table.find(key);

        if (it == key_table.end())
        {
            return -1;
        }
        
        auto node = it->second;

        int val = node->val, freq = node->freq;

        freq_table[freq].erase(node);

        if (freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);

            if (freq_min == freq)
            {
                freq_min++;
            }
        }
        
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));

        key_table[key] = freq_table[freq + 1].begin();

        return val;
    }
    
    void put(int key, int value) {
        if (capacity <= 0)
        {
            return;
        }
        
        auto it = key_table.find(key);

        if (it == key_table.end())
        {
            if (key_table.size() == capacity)
            {
                auto it_min = freq_table[freq_min].back();

                key_table.erase(it_min.key);

                freq_table[freq_min].pop_back();

                if (freq_table[freq_min].size() == 0)
                {
                    freq_table.erase(freq_min);
                }
            }
            
            freq_table[1].push_front(Node(key, value, 1));

            key_table[key] = freq_table[1].begin();

            freq_min = 1;
        }
        else
        {
            auto node = it->second;

            int freq = node->freq;

            freq_table[freq].erase(node);

            if (freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);

                if (freq_min == freq)
                {
                    freq_min++;
                }
            }
            
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));

            key_table[key] = freq_table[freq + 1].begin();
        }
    }

private:
    int capacity, freq_min;

    unordered_map<int, list<Node>::iterator> key_table;

    unordered_map<int, list<Node>> freq_table;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

