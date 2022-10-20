/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

// tag: BFS (iteration);
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> levels;
        vector<int> currLevel;

        queue<Node *> q;
        q.push(root);

        int qSize = q.size();

        while (!q.empty()) {
            Node *node = q.front();
            if (!qSize) {
                qSize = q.size();
                levels.push_back(currLevel);
                currLevel.clear();
            }
            qSize--;
            q.pop();

            if (!node) {
                continue;
            }

            currLevel.push_back(node->val);

            for (auto child : node->children) {
                q.push(child);
            }
        }

        if (currLevel.size()) levels.push_back(currLevel);
        return levels;
    }
};
// @lc code=end

