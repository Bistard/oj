/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start

// tag: 1+3+5+7... = square number
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        
        return num == 0;
    }
};

// tag: binary search - log(n)
class BinarySearch {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        
        int l = -1, r = num;
        int m;

        while (l + 1 != r) {
            m = (r + l) / 2;
            float res = (float)num / (float)m;

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

// tag: Newton Method
class NewtonMethod {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) >> 1;
        }
        return x * x == num;
    }
};
// @lc code=end

