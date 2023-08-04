/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// tag: Binary Search
class Solution {
public:
    int firstBadVersion(int n) {
        size_t l = -1, r = n;
        size_t m;
        bool isBad;

        while (l + 1 != r) {

            m = (l + r) / 2;

            isBad = isBadVersion(m);
            if (!isBad && isBadVersion(m + 1)) {
                return m + 1;
            }

            if (isBad) {
                r = m;
            } else {
                l = m;
            }
        }

        return m;
    }
};
// @lc code=end

