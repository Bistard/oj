/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return dfs(head, nullptr);
    }

    ListNode *dfs(ListNode *node, ListNode *prev) {
        if (!node) {
            return prev;
        }
        
        ListNode *nextNode = node->next;
        node->next = prev;
        ListNode *ifFound = dfs(nextNode, node);
        node->next = nextNode;
        
        return ifFound ? ifFound : nullptr;
    }
};
// @lc code=end

