/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

// cached
class Solution {
private:
    vector<int> seen;
public:
    Solution() {
        seen = vector<int>(38, -1);
        seen[0] = 0;
        seen[1] = 1;
        seen[2] = 1;
    }

    int tribonacci(int n) {
        if (seen[n] != -1) {
            return seen[n];
        }
        
        seen[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return seen[n];
    }
};

// no memory cache (TLE)
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
// @lc code=end

