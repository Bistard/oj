/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start

// tag: Math O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        return (int) (sqrt(2 * (long) n + 0.25) - 0.5);
    }
};

// tag: O(n)
class Iteration {
public:
    int arrangeCoins(int n) {
        int rowSize = 1;
        int complete = 0;
        while (n >= rowSize) {
            n -= rowSize;
            ++complete;
            ++rowSize;
        }
        
        return complete;
    }
};
// @lc code=end

