/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        int maxLevelSum = INT_MIN;
        int idx = -1;

        int currLevel = 0;
        
        while (!q.empty()) {
            currLevel++;
            const int levelSize = q.size();
            int currLevelSum = 0;
            
            // iterate level
            for (int i = 0; i < levelSize; i++) {
                auto node = q.front();
                q.pop();
                currLevelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // check level sum
            if (currLevelSum > maxLevelSum) {
                maxLevelSum = currLevelSum;
                idx = currLevel;
            }
        }

        return idx;
    }
};
// @lc code=end

