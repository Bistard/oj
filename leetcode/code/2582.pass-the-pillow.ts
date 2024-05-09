/*
 * @lc app=leetcode id=2582 lang=ts
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
function passThePillow(n: number, time: number): number {
    const round = Math.floor(time / (n - 1));
    const left = time % (n - 1);

    if (round % 2 === 0) {
        return left + 1;
    } else {
        return n - left;
    }
};
// @lc code=end

