/*
 * @lc app=leetcode id=2437 lang=cpp
 *
 * [2437] Number of Valid Clock Times
 */
// @lc code=start

class Solution {
public:
    int countTime(string time) {
        const int n = time.length();
        if (n != 5) return false;
        if (time[2] != ':') return false;
        
        bool first = false, second = false, third = false, forth = false;
        first = time[0] == '?';
        second = time[1] == '?';
        third = time[3] == '?';
        forth = time[4] == '?';
        
        int cnt = 1;
        if (third) cnt *= 6;
        if (forth) cnt *= 10;
        
        if (first && second) cnt *= 24;
        else if (!first && second) {
            if (time[0] == '0') cnt *= 10;
            else if (time[0] == '1') cnt *= 10;
            else if (time[0] == '2') cnt *= 4;
        }
        else if (first && !second) {
            if (time[1] == '0') cnt *= 3;
            else if (time[1] <= '3') cnt *= 3;
            else cnt *= 2;
        }
        
        return cnt;
    }
};

// @lc code=end