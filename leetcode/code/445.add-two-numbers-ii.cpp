/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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

#include <bits/stdc++.h>
using namespace std;

// tag: stack; time: O(n + m); space: O(n + m);
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode *> s1;
        stack<ListNode *> s2;

        ListNode *curr1 = l1, *curr2 = l2;
        while (curr1 || curr2) {
            if (curr1) {
                s1.push(curr1);
                curr1 = curr1->next;
            }
            if (curr2) {
                s2.push(curr2);
                curr2 = curr2->next;
            }
        }
        
        ListNode *curr = nullptr;
        bool carry = false;

        while (!s1.empty() && !s2.empty()) {
            int d1 = s1.top()->val;
            int d2 = s2.top()->val;

            int digit = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;

            ListNode *node = new ListNode(digit);
            node->next = curr;
            curr = node;

            s1.pop();
            s2.pop();
        }
        
        while (!s1.empty()) {
            int d = s1.top()->val;
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;

            ListNode *node = new ListNode(digit);
            node->next = curr;
            curr = node;
            s1.pop();
        }

        while (!s2.empty()) {
            int d = s2.top()->val;
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;

            ListNode *node = new ListNode(digit);
            node->next = curr;
            curr = node;
            s2.pop();
        }

        if (carry) {
            ListNode *node = new ListNode(1);
            node->next = curr;
            curr = node;
        }
        
        return curr;
    }
};
// @lc code=end

