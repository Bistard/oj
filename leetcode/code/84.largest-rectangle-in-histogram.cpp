/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return __divide(heights, 0, heights.size() - 1);
    }

    int __divide(vector<int> &heights, int l, int r) {
        
        if (l > r) {
            return 0;
        }

        // base case
        if (l == r) {
            return heights[l];
        }
        
        const int mid = (l + r) / 2;

        const int leftMax = __divide(heights, l, mid);
        const int rightMax = __divide(heights, mid + 1, r);

        int minHeight = heights[mid];
        int currLeft = mid, currRight = mid;
        int area = heights[mid];
        
        // Start from the middle and expand outwards, try to find the max rect.
        while (l < currLeft || currRight < r) {
            if (currRight < r && (currLeft == l || heights[currLeft - 1] < heights[currRight + 1])) {
                currRight++;
                minHeight = min(minHeight, heights[currRight]);
            } else {
                currLeft--;
                minHeight = min(minHeight, heights[currLeft]);
            }
            area = max(area, (currRight - currLeft + 1) * minHeight);
        }

        return max({leftMax, rightMax, area});
    }
};
// @lc code=end

