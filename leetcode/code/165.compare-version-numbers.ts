/*
 * @lc app=leetcode id=165 lang=ts
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
function compareVersion(version1: string, version2: string): number {
    let s1 = version1.split('.'), i = 0, len1 = s1.length;
    let s2 = version2.split('.'), j = 0, len2 = s2.length;
    while (i < len1 || j < len2) {
        const res = cmpSection(s1[i] ?? '0', s2[j] ?? '0');
        if (res) return res;
        i++; j++;
    }
    return 0;
};

function cmpSection(section1: string, section2: string): number {
    let i = 0, len1 = section1.length;
    let j = 0, len2 = section2.length;

    // ignore leading zeroes
    while (i < len1 && section1[i] === '0') i++;
    while (j < len2 && section2[j] === '0') j++;

    const num1 = Number(section1.slice(i));
    const num2 = Number(section2.slice(j));
    
    return (num1 > num2)
        ? 1
        : (num1 < num2) ? -1 : 0;
}
// @lc code=end

