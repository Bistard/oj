/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start

// tag: O(10)
// https://www.youtube.com/watch?v=-5z9dimxxmI
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

// tag: O(32)
class O32Faster {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;

        for (int i = 0; i < 32; ++i) {
            x <<= 1;
            x = x | (n & 1);
            n >>= 1;
        }

        return x;
    }
};

// tag: O(32)
class O32 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;

        for (int i = 0; i < 32; ++i) {
            int bit = n & (1 << i);
            if (bit) {
                x = x | (1 << (31 - i));
            }
        }

        return x;
    }
};
// @lc code=end

