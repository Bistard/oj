/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: question specific (limited to 3000); time: O(1);
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};

// tag: math; time: O(1);
class MySolution {
public:
    string intToRoman(int num) {
        string roman;

        // larger than 1000
        if (num >= 1000) {
            int M = num / 1000;
            num %= 1000;
            for (int i = 0; i < M; i++) roman += 'M';
        }

        // larger than 500
        if (num >= 900) {
            num %= 900;
            roman += "CM";
        } else if (num >= 500) {
            num %= 500;
            roman += 'D';
        }

        // larger than 100
        if (num >= 400) {
            num %= 400;
            roman += "CD";
        } else if (num >= 100) {
            int C = num / 100;
            num %= 100;
            for (int i = 0; i < C; i++) roman += 'C';
        }

        // larger than 50
        if (num >= 90) {
            num %= 90;
            roman += "XC";
        } else if (num >= 50) {
            num %= 50;
            roman += 'L';
        }

        // larger than 10
        if (num >= 40) {
            num %= 40;
            roman += "XL";
        } else if (num >= 10) {
            int X = num / 10;
            num %= 10;
            for (int i = 0; i < X; i++) roman += 'X';
        }

        // larger than 5
        if (num == 9) {
            num %= 9;
            roman += "IX";
        } else if (num >= 5) {
            num %= 5;
            roman += 'V';
        }

        // larger than 1
        if (num == 4) {
            num %= 4;
            roman += "IV";
        } else {
            int I = num;
            for (int i = 0; i < I; i++) roman += 'I';
        }

        return roman;
    }
};
// @lc code=end

