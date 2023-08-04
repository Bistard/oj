/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        const int lowest = nums[0] + k;
        const int highest = nums[n - 1] - k;
        int dis = nums[n - 1] - nums[0]; // the range of possible answer is [lowest, highest].
        
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];

            /**
             * Assuming there is a point has the value between a and b such that:
             * (A[0]+K, A[1]+K, ..., A[i]+K, POINT, A[i+1]-K, ..., A[n-1]-K, A[n]-K). 
             * Then we just do a linear scan to find the minimum score.
             */

            int lowVal = min(lowest, b - k);   // the smallest on the left partition
            int highVal = max(highest, a + k); // the largest on the right partition
            dis = min(dis, highVal - lowVal);
        }

        return dis;
    }
};
// @lc code=end

