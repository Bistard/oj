/*
 * @lc app=leetcode id=2420 lang=javascript
 *
 * [2420] Find All Good Indices
 * 
 * explanations
 * - https://leetcode.com/problems/find-all-good-indices/discuss/2620565/DP-C%2B%2BJavaPython-%2B-Intuition
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var goodIndices = function(nums, k) {
    const len = nums.length;
    const indice = [];
    const prefix = [1], suffix = [1];
    let i;
    
    // prefix
    for (i = 1; i < len; i++) {
        if (nums[i] <= nums[i - 1]) {
            prefix[i] = prefix[i - 1] + 1;
        } else {
            prefix[i] = 1;
        }
    }

    // suffix
    for (i = 1; i < len; i++) {
        if (nums[len - i - 1] <= nums[len - i]) {
            suffix[i] = suffix[i - 1] + 1;
        } else {
            suffix[i] = 1;
        }
    }

    // dp
    for (i = k; i < len - k; i++) {
        if (prefix[i - 1] >= k && suffix[len - i - 2] >= k) {
            indice.push(i);
        }
    }

    return indice;
};
// @lc code=end

var bruteforce = function(nums, k) {
    const len = nums.length - k;
    const indice = [];

    let frontPrev, endPrev, good;
    let frontCurr, endCurr;

    for (let i = k; i < len; i++) {
        frontPrev = nums[i - 1];
        endPrev = nums[i + 1];
        good = true;

        for (let j = 1; j <= k; j++) {
            frontCurr = nums[i - j];
            endCurr = nums[i + j];

            if (frontCurr < frontPrev || endPrev > endCurr) {
                good = false;
                break;
            }

            frontPrev = frontCurr;
            endPrev = endCurr;
        }

        if (good) {
            indice.push(i);
        }
    }

    return indice;
};
