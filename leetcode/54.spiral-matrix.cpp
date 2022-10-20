/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

// time: O(M); space: O(1);
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> result;

        const int n = mat.size();
        const int m = mat[0].size();

        int dir = TOP;

        int top = 0;
        int right = m - 1;
        int bottom = n - 1;
        int left = 0;

        while (top <= bottom && left <= right) {
            
            if (dir == TOP) {
                for (int j = left; j <= right; j++) {
                    result.push_back(mat[top][j]);
                }
                top++;
            }
            else if (dir == RIGHT) {
                for (int i = top; i <= bottom; i++) {
                    result.push_back(mat[i][right]);
                }
                right--;
            }
            else if (dir == BOTTOM) {
                for (int j = right; j >= left; j--) {
                    result.push_back(mat[bottom][j]);
                }
                bottom--;
            }
            else {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return result;
    }
};
// @lc code=end

