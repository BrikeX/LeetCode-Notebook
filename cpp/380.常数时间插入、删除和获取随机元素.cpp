/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();

        memo.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (memo.count(val))
        {
            return false;
        }
        
        memo[val] = nums.size();

        nums.push_back(val);

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!memo.count(val))
        {
            return false;
        }
        
        int index = memo[val];

        memo[nums.back()] = index;

        swap(nums[index], nums.back());

        nums.pop_back();

        memo.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;

    unordered_map<int, int> memo;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

