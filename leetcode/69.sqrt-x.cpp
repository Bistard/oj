/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start

// tag: newton 
class Solution {
public:
    int mySqrt(int x) {
        long n = x;
        while (n * n > x) {
            n = (n + x / n) / 2;
        }

        return n;
    }
};
// @lc code=end

