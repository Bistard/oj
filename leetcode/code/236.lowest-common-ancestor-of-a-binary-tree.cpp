/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

class Solution {
private:
    set<int> seen;
    TreeNode *p;
    TreeNode *q;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;

        return dfs(root);
    }

    TreeNode *dfs(TreeNode *node) {
        if (!node) {
            return nullptr;
        }

        // founded, backtracing.
        if (node->val == p->val || node->val == q->val) {
            return node;
        }
        
        TreeNode *leftFound = dfs(node->left);
        TreeNode *rightFound = dfs(node->right);
        
        if (leftFound && rightFound) {
            return node;
        }
        
        return leftFound ? leftFound : rightFound;
    }
};
// @lc code=end

