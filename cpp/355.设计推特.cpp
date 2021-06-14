/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        // 哈希表
        timeStamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post_map[userId].push_back({++timeStamp, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        priority_queue<pair<int, int>, vector<pair<int, int>>, postComparison> news_queue;

        sub_map[userId].insert(userId);

        for (auto &&id : sub_map[userId])
        {
            for (auto &&post : post_map[id])
            {
                news_queue.push(post);
            }
        }
        
        while (!news_queue.empty() && result.size() < 10)
        {
            result.push_back(news_queue.top().second);

            news_queue.pop();
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        sub_map[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        sub_map[followerId].erase(followeeId);
    }

private:
    int timeStamp;

    unordered_map<int, unordered_set<int>> sub_map;

    unordered_map<int, vector<pair<int, int>>> post_map;

    struct postComparison
    {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.first < b.first;
        }
    };
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

