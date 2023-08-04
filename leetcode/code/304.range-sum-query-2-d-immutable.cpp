/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: prefix sum; time: O(mn);
class NumMatrix {
private:
    int n, m;
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix): 
        n   { (int)matrix.size() }, 
        m   { (int)matrix[0].size() }, 
        mat { vector<vector<int>>(n, vector<int>(m, 0)) }
    {
        mat[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++) mat[i][0] = mat[i - 1][0] + matrix[i][0];
        for (int j = 1; j < m; j++) mat[0][j] = mat[0][j - 1] + matrix[0][j];
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        int sum = mat[x2][y2];
        if (x1 > 0) sum -= mat[x1 - 1][y2];
        if (y1 > 0) sum -= mat[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) sum += mat[x1 - 1][y1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

