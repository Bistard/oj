/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

// tag: union-find
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> u(n);
        for (int i = 0; i < n; ++i) {
            u[i] = i;
        }
        
        for (auto &edge : edges) {
            unions(u, edge[0], edge[1]);
        }

        return find(u, source) == find(u, destination);
    }

    int find(vector<int> &u, int x) {
        if (u[x] != x) {
            u[x] = find(u, u[x]); // path compression
        }
        return u[x];
    }

    void unions(vector<int> &u, int x, int y) {
        int rootX = find(u, x);
        int rootY = find(u, y);
        
        if (rootX == rootY) {
            return;
        }

        u[rootX] = rootY;
    }
};
// @lc code=end

