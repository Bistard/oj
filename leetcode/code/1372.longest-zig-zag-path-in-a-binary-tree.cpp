/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
private:
    int _maxDepth = 0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        return _maxDepth;
    }

    void dfs(TreeNode *node, bool fromLeft, int depth) {
        if (!node) {
            return;
        }

        if (fromLeft) {
            dfs(node->left, fromLeft, 1);
            dfs(node->right, !fromLeft, depth + 1);
        } else {
            dfs(node->right, fromLeft, 1);
            dfs(node->left, !fromLeft, depth + 1);
        }

        _maxDepth = max(_maxDepth, depth);
    }
};
// @lc code=end

