/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: O(n);
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> incoming(n, 0);
        for (auto &edge : edges) {
            incoming[edge[1]]++;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (incoming[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};
// @lc code=end

