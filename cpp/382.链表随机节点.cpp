/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ptr = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int result = ptr->val;

        ListNode* head = ptr->next;

        int i = 2;

        while (head)
        {
            if (rand() % i == 0)
            {
                result = head->val;
            }
            
            head = head->next;

            i++;
        }
        
        return result;
    }

private:
    ListNode* ptr;

    // srand(time(NULL));
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

