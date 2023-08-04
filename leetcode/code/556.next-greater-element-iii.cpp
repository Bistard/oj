/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: string; time: O(1);
class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        const int n = s.length();

        // find the subarray from the behind that is ascending.
        int i;
        for (i = n - 1; i >= 0; i--) {
            if (i == 0) break;
            char digit = s[i], prevDigit = s[i - 1];
            if (digit > prevDigit) {
                break;
            }
        }

        // the whole number is descending, no can do.
        if (i == 0) return -1;

        // sort the subarray in ascending way
        vector<char> subarr;
        for (int idx = i; idx < n; idx++) subarr.push_back(s[idx]);
        sort(subarr.begin(), subarr.end(), [](char a, char b) { return a < b; });

        // copy the sorted part into the original string
        string concat;
        for (auto c : subarr) concat += c;
        for (int idx = i; idx < n; idx++) s[idx] = concat[idx - i];
        
        // start from (i - 1), find the next greater value to replace.
        for (int idx = i; idx < n; idx++) {
            if (s[idx] > s[i - 1]) {
                swap(s[idx], s[i - 1]);
                try {
                    return stoi(s);
                } catch(const exception &e) {
                    return -1;
                }
            }
        }
        
        return -1;
    }
};
// @lc code=end

