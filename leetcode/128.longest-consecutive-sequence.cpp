/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// tag: union-find
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        // since each number may not be distinct, we use map instead of array.
        unordered_map<int, int> v;

        for (int num : nums) {
            if (v.find(num) == v.end()) {
                v[num] = num;
            }
        }

        for (auto &pair : v) {
            const int num = pair.first;
            const int scope = pair.second;
            
            if (v.find(num - 1) != v.end()) {
                unions(v, find(v, num), find(v, num - 1));
            }

            if (v.find(num + 1) != v.end()) {
                unions(v, find(v, num), find(v, num + 1));
            }
        }

        // maintains the size of each sequence.
        int maxlen = 1;
        unordered_map<int, int> s;

        for (auto &pair : v) {
            const int root = find(v, pair.second);
            if (s.find(root) == s.end()) {
                s[root] = 1;
            } else {
                s[root] += 1;
                maxlen = max(maxlen, s[root]);
            }
        }

        return maxlen;
    }

    int find(unordered_map<int, int> &u, int x) {
        if (u[x] != x) {
            u[x] = find(u, u[x]); // path compression
        }
        return u[x];
    }

    void unions(unordered_map<int, int> &u, int x, int y) {
        int rootX = find(u, x);
        int rootY = find(u, y);
        
        if (rootX == rootY) {
            return;
        }

        u[rootX] = rootY;
    }
};
// @lc code=end
