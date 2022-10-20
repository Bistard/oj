/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// time: O(n);
class Solution {
public:
    int romanToInt(string s) {
        const int n = s.length();

        char prev = ' ';
        int res = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            
            if (c == 'I') res += 1;
            else if (c == 'V') res += 5;
            else if (c == 'X') res += 10;
            else if (c == 'L') res += 50;
            else if (c == 'C') res += 100;
            else if (c == 'D') res += 500;
            else if (c == 'M') res += 1000;

            if (c == 'I' && (prev == 'V' || prev == 'X')) res -= 2;
            if (c == 'X' && (prev == 'L' || prev == 'C')) res -= 20;
            if (c == 'C' && (prev == 'D' || prev == 'M')) res -= 200;

            prev = c;
        }

        return res;
    }
};
// @lc code=end

