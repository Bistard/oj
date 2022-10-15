/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// tag: DFS (recursive)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode *node) {
        if (!node) return;
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        dfs(node->left);
        dfs(node->right);
    }
};
// @lc code=end

