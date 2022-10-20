/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// tag: brute force; time: O(mn * log(n)) where m is the number of queries; space: O(n);
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vi &nums, vi &l, vi &r) {
        
        const int n = l.size();
        vector<bool> result(n, true);

        for (int idx = 0; idx < n; idx++) {
            int i = l[idx];
            int j = r[idx];
            
            int len = j - i + 1;
            if (len == 1) continue;

            vector<int> arr(nums.begin() + i, nums.begin() + j + 1);
            sort(arr.begin(), arr.end());

            int diff = arr[1] - arr[0];
            for (int i = 2; i < len; i++) {
                if (arr[i] - arr[i - 1] != diff) {
                    result[idx] = false;
                    break;
                }
            }
        }

        return result;
    }
};
// @lc code=end

