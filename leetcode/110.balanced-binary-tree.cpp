/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }

    bool balanced = true;

    int dfs(TreeNode *node) {
        if (!node) {
            return 1;
        }

        int leftDepth = dfs(node->left) + 1;
        int rightDepth = dfs(node->right) + 1;

        if (abs(leftDepth - rightDepth) > 1) {
            balanced = false;
        }
        
        return max(leftDepth, rightDepth);
    }
};
// @lc code=end

