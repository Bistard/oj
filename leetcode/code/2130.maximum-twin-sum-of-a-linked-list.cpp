/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

// tag: slow-fast pointers
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> sum;
        int len = 0, maxSum = 0;

        ListNode *slow = head, *fast = head;

        while (slow) {
            if (fast && fast->next) {
                // let fast-ptr keep going
                len += 2;
                sum.push_back(slow->val);
                fast = fast->next->next;
            } 
            else {
                // the fast ptr reaches the end, start sum up.
                int idx = len / 2 - 1;
                sum[idx] += slow->val;
                maxSum = max(maxSum, sum[idx]);
                len -= 2;
            }

            slow = slow->next;
        }
        
        return maxSum;
    }
};
// @lc code=end
