/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // 优先队列
    }
    
    void addNum(int num) {
        if (small.size() >= large.size())
        {
            small.push(num);

            large.push(small.top());

            small.pop();
        }
        else
        {
            large.push(num);

            small.push(large.top());

            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() < large.size())
        {
            return large.top();
        }
        else if (small.size() > large.size())
        {
            return small.top();
        }
        
        return (small.top() + large.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<int>> small;

    priority_queue<int, vector<int>, greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

