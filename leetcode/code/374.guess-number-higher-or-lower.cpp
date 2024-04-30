/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution20231003 {
    public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int m;

        while (l <= r) {
            m = l + (r - l) / 2;

            int res = guess(m);
            if (res == 0) {
                return m;
            }

            if (res == -1) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int guessNumber(int n) {
        unsigned int l = 1, r = n;
        unsigned int m = 1;
        char g;

        while (l < r) {
            m = l + (r - l) / 2;

            g = guess(m);
            if (g == 0) {
                return m;
            }

            if (g == -1) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        
        return l;
    }
};
// @lc code=end

