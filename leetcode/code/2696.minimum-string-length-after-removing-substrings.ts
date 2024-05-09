/*
 * @lc app=leetcode id=2696 lang=ts
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
function minLength(s: string): number {
    let prevS: string;
    do {
        prevS = s;
        s = s.replace('AB', '').replace('CD', '');
    } while (prevS !== s);
    
    return s.length;
};

// @lc code=end

