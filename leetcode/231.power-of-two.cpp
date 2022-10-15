/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start

// tag: bit manipulation - O(1)
// https://leetcode.com/problems/power-of-two/discuss/1638707/PythonC%2B%2BJava-Detailly-Explain-Why-n-and-n-1-Works-oror-1-Line-oror-100-Faster-oror-Easy
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
    }
};

// tag: bit manipulation - O(32)
class O32 {
public:
    bool isPowerOfTwo(int n) {
        int bitCnt = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                bitCnt++;
                if (bitCnt > 1) return false;
            }
        }

        // make sure the signed digit is not 1.
        // example: -2147483648 => 10000000000000000000000000000000
        return bitCnt == 1 && ((n & (1 << 31)) == 0);
    }
};
// @lc code=end

