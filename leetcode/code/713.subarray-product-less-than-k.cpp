/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: sliding window; time: O(n); space: O(1);
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();
        int cnt = 0;
        
        int product = 1;
        int start = 0, end = 0; // range is [start, end]
        while (start < n && end < n) {
            if ((product * nums[end]) < k) {
                product *= nums[end];
                cnt += (end - start) + 1;
                end++;
            } else {
                if (end - start > 0) {
                    product /= nums[start];
                } else {
                    end++;
                }
                start++;
            }
        }
        
        return cnt;
    }
};
// @lc code=end

