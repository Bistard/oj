/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: hashmap, sliding window; time: O(n); space: O(n);
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (!k) return false;

        const int n = nums.size();
        unordered_set<int> window;

        int i = 0, j = min(k, n - 1);
        for (int idx = 0; idx < j; idx++) {
            if (window.find(nums[idx]) != window.end()) return true;
            window.insert(nums[idx]);
        }

        while (j <= n - 1) {
            if (window.find(nums[j]) != window.end()) return true;
            window.erase(nums[i]);
            window.insert(nums[j]);
            i++;
            j++;
        }
        
        return false;
    }
};
// @lc code=end

