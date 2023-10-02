/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

#define MODULO (1e9 + 7)

// tag: prefix-sum
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        unordered_map<int, int> seen; // { value seen, seen for x times }
        seen[0] = 1;

        dfs(root, targetSum, &cnt, 0, seen);

        return cnt;
    }

    void dfs(TreeNode *node, const int targetSum, int *cnt, int prefixSum, unordered_map<int, int> &seen) {
        if (!node) {
            return;
        }

        prefixSum += node->val;
        prefixSum %= (int)MODULO;
        
        const int required = prefixSum - targetSum;
        (*cnt) += seen[required];

        seen[prefixSum]++;
    
        dfs(node->left, targetSum, cnt, prefixSum, seen);
        dfs(node->right, targetSum, cnt, prefixSum, seen);

        seen[prefixSum]--;
    }
};
// @lc code=end

