/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] sum of square numbers
 */
// @lc code=start

// tag: binary search - O(sqrt(c) * log(c))
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a <= (int)(sqrt(c)); ++a) {
            long b2 = c - a * a;
            if (isPerfectSquare(b2)) {
                return true;
            }
        }
        return false;
    }

    // Newton Method
    bool isPerfectSquare(int num) {
        if (num == 1 || num == 0) return true;
        
        long l = -1, r = num;
        long m;

        while (l + 1 != r) {
            m = (r + l) / 2;
            double res = (double)num / (double)m;

            if (m == res) {
                return true;
            }

            if (m < res) {
                l = m;
            } else {
                r = m;
            }
        }
        
        return false;
    }
};

// brute force -> newton method
class BruteForce {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            long b2 = c - a * a;
            if (isPerfectSquare(b2)) {
                return true;
            }
        }
        return false;
    }

    // Newton Method
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
};

// @lc code=end