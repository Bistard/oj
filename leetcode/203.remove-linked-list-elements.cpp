/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start

// tag: space - O(n) [but short code]
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

// tag: one pointer
class OnePointer {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }

        while (head && head->val == val) {
            head = head->next;
        }
        
        ListNode *node = head;
        while (node) {
            if (node->next && node->next->val == val) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }

        return head;
    }
};

// tag: two pointers
class TwoPointers {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }

        while (head && head->val == val) {
            head = head->next;
        }
        
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node) {
            if (node->val == val) {
                ListNode *next = node->next;
                if (prev) {
                    prev->next = next;
                }
                node = prev;
            }

            prev = node;
            node = node->next;
        }

        return head;
    }
};
// @lc code=end

