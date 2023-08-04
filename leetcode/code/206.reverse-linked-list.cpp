/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

// tag: iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *nextNode = nullptr, *prevNode = nullptr;

        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        

        return prevNode;
    }
};

// tag: recursive
class Recursive {
public:
    ListNode* reverseList(ListNode* head) {
        if (head) {
            dfs(head, nullptr);
        }
        return root;
    }

    ListNode *root = nullptr;

    void dfs(ListNode *node, ListNode *prev) {
        if (node->next == nullptr) {
            node->next = prev;
            root = node;
            return;
        }

        dfs(node->next, node);
        node->next = prev;
    }
};
// @lc code=end

