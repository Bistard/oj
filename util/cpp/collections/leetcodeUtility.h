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

TreeNode* 
buildTree(const vector<int>& arr) {
    
    // assuming -1 represents null
    if (arr.empty() || arr[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void
bfsTemplate(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        const int levelSize = q.size();
        
        // iterate level
        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = q.front();

            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // after every level
    }
}