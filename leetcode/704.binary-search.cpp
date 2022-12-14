/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        int m;
        while (l + 1 != r) {
            m = (l + r) / 2;
            
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] > target) {
                r = m;
            }

            else {
                l = m;
            }
        }

        return -1;        
    }
};
// @lc code=end

