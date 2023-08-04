/*
 * @lc app=leetcode id=2421 lang=javascript
 *
 * [2421] Number of Good Paths
 */

// @lc code=start

function arr2d(width, height, fill) {
    if (fill) return new Array(width).fill(new Array(height).fill(fill));
    else return new Array(width).fill(new Array(height).fill(0));
}

/**
 * @param {number[]} vals
 * @param {number[][]} edges
 * @return {number}
 */
var numberOfGoodPaths = function(vals, edges) {
    const size = vals.length;
    let goodPathCnt = 0;
    let start, end;

    // builds graph
    const g = arr2d(size, size, 0);
    for ([start, end] of edges) {
        g[start][end] = 1;
    }

    const goodPath = new Map();

    // dfs the tree
    const dfs = (node, children) => {

    };

    // (vals[i] === 0) => pass (it is the minimum)

    dfs(g[0][0], g[0]);

    return goodPathCnt;
};
// @lc code=end

