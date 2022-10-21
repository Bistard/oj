/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// time: O(n);
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        const int n = nums.size();
        
        int minVal = 1e4, maxVal = 0;
        for (auto num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        if (maxVal - minVal > k * 2) {
            return maxVal - minVal - 2 * k;
        } else {
            return 0;
        }
    }
};
// @lc code=end

