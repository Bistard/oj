#pragma once

#include "../utility.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode *
generateListFromArray(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    FOR(i, 1, arr.size()) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

TreeNode *
generateTreeFromSegmentTree(vector<int> arr) {
    std::function<TreeNode * (vi &, int, int)> aux;
    
    aux = [&](vi &arr, int l, int r) -> TreeNode * {
        if (l + 1 == r) {
            return nullptr;
        }

        int m = l + (r - l) / 2;
        TreeNode *node = new TreeNode(arr[m]);
        
        node->left = aux(arr, l, m);
        node->right = aux(arr, m, r);
        return node;
    };

    return aux(arr, -1, arr.size());
}