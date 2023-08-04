/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
private:
    int depth = 0;
    ListNode *newhead = nullptr;
    ListNode *oldhead = nullptr;
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head) {
            return head;
        }

        const int len = length(head);
        k = k % len;

        if (!k) {
            return head;
        }

        oldhead = head;
        loop(head, k);
        
        return newhead;
    }

    int length(ListNode *node) {
        if (!node->next) {
            return 1;
        }
        
        return length(node->next) + 1;
    }

    int loop(ListNode *node, int rotate) {
        
        if (node->next) {
            depth = loop(node->next, rotate) + 1;
            
            // current node will be the new end. It's next node will be the new hea
            if (depth == rotate) {
                newhead = node->next;
                node->next = nullptr;
            }

            return depth;
        } 

        // reaching end, points the current tail to the original head.
        node->next = oldhead;
        return 0;
    }
};
// @lc code=end

