/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        
        dfs(root, INT_MIN, &cnt);

        return cnt;
    }

    void dfs(TreeNode *node, int parent, int *cnt) {
        if (!node) {
            return;
        }

        if (node->val >= parent) {
            (*cnt)++;
        }

        dfs(node->left, max(node->val, parent), cnt);
        dfs(node->right, max(node->val, parent), cnt);
    }
};
// @lc code=end

