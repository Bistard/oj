/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        vector<int> seen(n, 1);

        for (int num : nums) {
            seen[num - 1]--;
        }

        int duplicate = 0;
        int missing = 0;
        for (int i = 0; i < n; i++) {
            int cnt = seen[i];
            if (cnt == -1) {
                duplicate = i + 1;
            } else if (cnt == 1) {
                missing = i + 1;
            }
        }

        return {duplicate, missing};
    }
};
// @lc code=end

