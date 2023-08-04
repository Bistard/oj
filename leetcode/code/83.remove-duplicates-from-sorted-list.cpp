/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<bool> visited(200, false);

        visited[head->val + 100] = true;
        ListNode *node = head;

        while (node) {
            if (node->next && visited[node->next->val + 100]) {
                node->next = node->next->next;
            } else {
                visited[node->val + 100] = true;
                node = node->next;
            }
        }
        
        return head;
    }
};
// @lc code=end

