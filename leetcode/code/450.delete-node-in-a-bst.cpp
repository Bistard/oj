/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // deleting node founded (no freeing memory here)
        else {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }
            
            TreeNode *leftmost = getLeftmost(root->right);
            root->val = leftmost->val;
            root->right = deleteNode(root->right, leftmost->val);
        }

        return root;
    }
    
    TreeNode* getLeftmost(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};
// @lc code=end

TreeNode* 
buildTree(const vector<int>& arr) {
    
    // assuming -1 represents null
    if (arr.empty() || arr[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> arr = {5,3,6,2,4,-1,7};  // -1 represents null
    TreeNode* root = buildTree(arr);

    Solution s;
    s.deleteNode(root, 7);
}