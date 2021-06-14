/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
        // 哈希表
        freq_max = 0;
    }
    
    void push(int val) {
        freq_max = max(freq_max, ++vf_map[val]);

        fv_map[vf_map[val]].push(val);
    }
    
    int pop() {
        int val = fv_map[freq_max].top();

        fv_map[freq_max].pop();

        if (fv_map[freq_max].size() == 0)
        {
            freq_max--;
        }
        
        vf_map[val]--;

        return val;
    }

private:
    unordered_map<int, int> vf_map;

    unordered_map<int, stack<int>> fv_map;

    int freq_max;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

