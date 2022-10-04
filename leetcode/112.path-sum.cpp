/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
private:
    int target;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        target = targetSum;
        return dfs(root, 0);
    }

    bool dfs(TreeNode *node, int sum) {
        if (sum + node->val == target) {
            if (!node->left && !node->right) {
                return true;
            }
        }

        bool res;

        if (node->left) {
            res = dfs(node->left, sum + node->val);
        }

        if (res) {
            return true;
        }

        if (node->right) {
            return dfs(node->right, sum + node->val);
        }
        
        return false;
    }
};
// @lc code=end

