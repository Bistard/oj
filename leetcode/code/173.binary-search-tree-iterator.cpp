/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

#include <bits/stdc++.h>
using namespace std;

class BSTIterator {
private:
    stack<TreeNode *> s;
    TreeNode *curr;
public:
    BSTIterator(TreeNode* root): curr {root} {}
    
    int next() {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();
        int val = curr->val;

        curr = curr->right;
        return val;
    }
    
    bool hasNext() {
        return curr || !s.empty();
    }
};
// @lc code=end

