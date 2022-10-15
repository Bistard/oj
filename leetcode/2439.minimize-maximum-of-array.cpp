/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */
// @lc code=start

// tag: prefix sum
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        const int n = nums.size();

        long sum = 0;
        long maxVal = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            // reason to have (sum + i) is to ceil the result of (sum / (i + 1)).
            maxVal = max(maxVal, (sum + i) / (i + 1));
        }

        return maxVal;
    }
};

// @lc code=end