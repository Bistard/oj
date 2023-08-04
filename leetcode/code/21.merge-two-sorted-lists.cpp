/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

// tag: no extra memory and used while loop
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        
        ListNode *root = new ListNode();
        ListNode *tail = root;

        while (list1 && list2) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;

        return root->next;
    }
};

// tag: no extra memory (but used recursive call)
class RecursiveCall {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        
        if (list1->val <= list2->val) {
            sort(list1, list1->next, list2);
            return list1;
        } else {
            sort(list2, list1, list2->next);
            return list2;
        }
    }

    ListNode *sort(ListNode* root, ListNode* list1, ListNode* list2) {
        if (!list1) {
            return root->next = list2;
        } else if (!list2) {
            return root->next = list1;
        }

        if (list1->val <= list2->val) {
            root->next = list1;
            return sort(root->next, list1->next, list2);
        } else {
            root->next = list2;
            return sort(root->next, list1, list2->next);
        }
    }
};

// tag: use extra memory
class ExtraMemory {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root = new ListNode();
        sort(root, list1, list2);
        return root->next;
    }

    void sort(ListNode *root, ListNode *list1, ListNode *list2) {
        if (!list1 || !list2) {
            root->next = list1 ? list1 : list2;
            return;
        }

        if (list1->val <= list2->val) {
            root->next = new ListNode(list1->val);
            return sort(root->next, list1->next, list2);
        }

        else {
            root->next = new ListNode(list2->val);
            return sort(root->next, list1, list2->next);
        }
    }
};

// @lc code=end

