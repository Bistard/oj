/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// time: O(M); space: O(1);
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n = mat.size();
        
        vector<bool> rotation(4, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // rotation degree 0
                if (mat[i][j] != target[i][j])
                    rotation[0] = rotation[0] & false;
                
                // rotation degree 90
                if (mat[i][j] != target[j][n - 1 - i])
                    rotation[1] = rotation[1] & false; 

                // rotation degree 180
                if (mat[i][j] != target[n - 1 - i][n - 1 - j])
                    rotation[2] = rotation[2] & false;
                
                // rotation degree 270
                if (mat[i][j] != target[n - 1 - j][i])
                    rotation[3] = rotation[3] & false;
            }
        }

        return rotation[0] || rotation[1] || rotation[2] || rotation[3];
    }
};

// time: O(8M); space: O(1);
class Rotate4Times {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n = mat.size();
        

        for (int _ = 0; _ < 4; _++) {
            // rotate mat first
            for (int i = 0; i < (n + 1) / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][n - 1 - i];
                    mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
                    mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
                    mat[n - 1 - j][i] = temp;
                }
            }

            // check if the same
            bool isSame = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        isSame = false;
                        goto end;
                    }
                }
            }

            end:
            if (isSame) return true;
        }

        return false;
    }
};
// @lc code=end

