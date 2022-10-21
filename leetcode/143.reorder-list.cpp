/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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


// tag: stack; time: O(n); space: O(n);
class Solution {
public:
    void reorderList(ListNode *head) {

        int len = 0;
        stack<ListNode *> s;

        ListNode *curr = head;
        while (curr) {
            s.push(curr);
            curr = curr->next;
            len++;
        }
        
        curr = head;
        for (int i = 0; i < len / 2; i++) {
            ListNode *first = curr;
            ListNode *second = s.top();

            second->next = first->next;
            first->next = second;
            
            curr = curr->next->next;
            s.pop();
        }

        curr->next = nullptr;
    }
};
// @lc code=end

