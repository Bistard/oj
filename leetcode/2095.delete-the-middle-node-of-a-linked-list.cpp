/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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

// tag: fast-slow pointers; time: O(n); space: O(1);
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head && !head->next) {
            return nullptr;
        }

        ListNode *fast = head->next->next, *slow = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next->next;

        return head;
    }
};

// tag: DFS; time: O(n); space: O(n);
class DFS {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head && !head->next) {
            return nullptr;
        }

        dfs(nullptr, head, 0);
        return head;
    }

    int dfs(ListNode *prev, ListNode *node, int depth) {
        if (!node) {
            return depth;
        }

        int len = dfs(node, node->next, depth + 1);
        if (depth == len / 2) {
            ListNode *next = node->next;
            prev->next = next;
        }

        return len;
    }
};
// @lc code=end

