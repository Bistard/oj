/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

// tag: BFS, queue
class Solution {
private:
    vector<int> rightSide;
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return rightSide;
        
        queue<TreeNode *> q;
        q.push(root);

        int levelCnt = 0;
        int levelSize = q.size();
        TreeNode *prevNode = nullptr;

        while (!q.empty()) {
            
            // the node is the last noe in the current level
            if (levelCnt == levelSize) {
                if (prevNode) {
                    rightSide.push_back(prevNode->val);
                }
                levelCnt = 0;
                levelSize = q.size();
            }
            
            // process the current node
            auto node = q.front();
            q.pop();
            prevNode = node;
            levelCnt++;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // always add the last node
        rightSide.push_back(prevNode->val);
        
        return rightSide;
    }
};
// @lc code=end

