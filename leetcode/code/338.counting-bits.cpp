/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

// tag: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n + 1);
        t[0] = 0;
        
        for(int i = 1; i <= n; ++i)
            t[i] = t[i / 2] + i % 2;
        
        return t;
    }
};

class Hacky {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            bits[i] = countBit(i);
        }

        return bits;
    }

    static int countBit(uint32_t num) {
        num = num - ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        return ((num + (num >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            bits[i] = countBit(i);
        }

        return bits;
    }

    int countBit(int num) {
        int mask = 1;
        int bitCount = 0;

        for (int i = 0; i < 32; i++) {
            int res = num & mask;
            if (res != 0) {
                bitCount++;
            }

            mask <<= 1;
        }

        return bitCount;
    }
};
// @lc code=end

