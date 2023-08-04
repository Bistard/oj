/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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

// time: O(h)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode *curr = root;
        while (curr) {
            if (val == curr->val) {
                return curr;
            }

            else if (val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return nullptr;
    }
};
// @lc code=end

