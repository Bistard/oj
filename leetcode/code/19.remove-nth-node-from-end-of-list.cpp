/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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

// tag: space - O(1) - using two pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};

// tag: space - O(m)
class ExtraSpace {
private:
    int N;
    int len;
    ListNode *found;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        N = n;
        return dfs(head, 1);
    }

    ListNode *dfs(ListNode *node, int depth) {
        if (node->next == nullptr) {
            len = depth;
            return nullptr;
        }

        found = dfs(node->next, depth + 1);
        if (found || (N == 1 && depth == len - 1)) {
            node->next = found;
            return node;
        }
        
        if (depth == len - N + 1) {
            return node->next;
        }

        return nullptr;
    }
};
// @lc code=end

