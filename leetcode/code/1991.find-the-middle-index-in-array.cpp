/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 */

// @lc code=start
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        for(int i = 0; i < n; i++) {
            sum -= nums[i];
            if(sum == left) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
// @lc code=end

