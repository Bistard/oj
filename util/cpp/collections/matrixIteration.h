#include "../utility.h"

void simpleIteration2D(vector<vector<int>> &mat) {
    const int n = mat.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            VALUE(make_pair(i, j));
        }
    }
}

void iterateRightTop2D(vector<vector<int>> &mat) {
    const int n = mat.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            VALUE(make_pair(j, i + j));
        }
    }
}

/**
 * 0   deg rotation : (i, j) will point to (i, j)
 * 90  deg rotation : (i, j) will point to (j, n - i - 1)
 * 180 deg rotation : (i, j) will point to (n - i - 1, n - j - 1)
 * 270 deg rotation : (i, j) will point to (n - j - 1, i)
 */
void rotateMatrix2D(vector<vector<int>> &mat) {
    const int n = mat.size();
    
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
            mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = temp;
        }
    }
}