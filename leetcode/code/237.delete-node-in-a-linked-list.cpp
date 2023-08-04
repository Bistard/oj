/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// time: O(1);
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// time: O(n);
class StupidSolution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *curr = node;

        while (curr->next) {
            curr->val = curr->next->val;
            
            if (!curr->next->next) {
                curr->next = nullptr;
                break;
            }
            
            curr = curr->next;
        }
    }
};
// @lc code=end

