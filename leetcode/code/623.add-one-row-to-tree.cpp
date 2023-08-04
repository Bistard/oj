/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) {
            return root;
        }

        if (depth == 1) {
            TreeNode *newroot = new TreeNode(val);
            newroot->left = root;

            return newroot;
        }
        else if (depth == 2) {
            TreeNode *leftNode = new TreeNode(val);
            TreeNode *rightNode = new TreeNode(val);

            leftNode->left = root->left;
            root->left = leftNode;
        
            rightNode->right = root->right;
            root->right = rightNode;
        } 
        else {
            addOneRow(root->left, val, depth - 1);
            addOneRow(root->right, val, depth - 1);
        }

        return root;
    }
};
// @lc code=end

