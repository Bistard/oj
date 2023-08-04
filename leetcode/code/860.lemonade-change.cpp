/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// time: O(n); space: O(n);
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        for (auto pay : bills) {
            m[pay] += 1;
            int change = pay - 5;
            
            if (change == 15) {
                if (m[5] >= 1 && m[10] >= 1) {
                    m[5]--;
                    m[10]--;
                } else if (m[5] >= 3) {
                    m[5] -= 3;
                } else {
                    return false;
                }
            }
            else if (change == 5) {
                if (m[5] >= 1) {
                    m[5]--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

