/*
 * @lc app=leetcode id=2419 lang=javascript
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let maxlen = 1;
    let currLen = 0;
    let maxNum = nums[0];
    
    for (let i = 0; i < nums.length; i++) {
        const currNum = nums[i];
        if (currNum === maxNum) {
            currLen++;
            if (currLen > maxlen) {
                maxlen = currLen;
            }
        }
        else if (currNum < maxNum) {
            currLen = 0;
            continue;
        }
        else {
            maxlen = 1;
            currLen = 1;
            maxNum = currNum;
        }
    }

    return maxlen;
};
// @lc code=end

