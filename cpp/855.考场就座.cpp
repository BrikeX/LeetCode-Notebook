/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
class IntervalComp
{
public:
    static int n;

    bool operator() (const vector<int>& a, const vector<int>& b) const
    {
        int dis_a = intervalDistance(a);

        int dis_b = intervalDistance(b);

        if (dis_a == dis_b)
        {
            return a[0] < b[0];
        }

        return dis_a > dis_b;
    }

    int intervalDistance(const vector<int>& v) const
    {
        if (v[0] == -1)
        {
            return v[1];
        }
        else if (v[1] == n)
        {
            return n - 1 - v[0];
        }
        
        return (v[1] - v[0]) / 2;
    }
};

int IntervalComp::n = 0;

class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;

        IntervalComp::n = n;

        vector<int> initial_v = {-1, n};

        addInterval(initial_v);
    }
    
    int seat() {
        vector<int> longest = *(seat_set.begin());

        int seat_start = longest[0], seat_end = longest[1];

        int seat;

        if (seat_start == -1)
        {
            seat = 0;
        }
        else if (seat_end == n)
        {
            seat = n - 1;
        }
        else
        {
            seat = (seat_end - seat_start) / 2 + seat_start;
        }
        
        vector<int> left = {seat_start, seat};

        vector<int> right = {seat, seat_end};

        eraseInterval(longest);

        addInterval(left);

        addInterval(right);

        return seat;
    }
    
    void leave(int p) {
        vector<int> right = start_map[p];

        vector<int> left = end_map[p];

        eraseInterval(right);

        eraseInterval(left);

        vector<int> v = {left[0], right[1]};

        addInterval(v);
    }

private:
    map<int, vector<int>> start_map, end_map;

    set<vector<int>, IntervalComp> seat_set;

    int n;

    void addInterval(vector<int>& v)
    {
        seat_set.emplace(v);

        start_map.emplace(v[0], v);

        end_map.emplace(v[1], v);
    }

    void eraseInterval(vector<int>& v)
    {
        seat_set.erase(v);

        start_map.erase(v[0]);

        end_map.erase(v[1]);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

