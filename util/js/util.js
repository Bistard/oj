
/**
 * @description Repeats a callback function for a given rounds.
 * @param {number} round The number of rounds.
 * @param {() => void} fn The callback function to be invoked in each round.
 * @returns {void}
 */
function repeat(round, fn) {
    for (let i = 0; i < round; i++) fn(i);
}

/**
 * @description Creates an 2D array.
 * @param {number} width The width of the array.
 * @param {number} height The height of the array.
 * @param {T | (() => T) | undefined} fill If to fill with given values. Either
 *      provider a primitive values to fill, or provide a function to create the 
 *      filling values, or by default fills with 0.
 * @returns {T[][]} A 2D array.
 */
function arr2d(width, height, fill) {
    if (typeof fill === 'function') return new Array(width).fill(new Array(height).fill(fill()));
    else if (fill) return new Array(width).fill(new Array(height).fill(fill));
    else return new Array(width).fill(new Array(height).fill(0));
}

/**
 * @description Creates an 3D array.
 * @param {number} width The width of the array.
 * @param {number} height The height of the array.
 * @param {number} depth The depth of the array.
 * @param {T | (() => T) | undefined} fill If to fill with given values. Either
 *      provider a primitive values to fill, or provide a function to create the 
 *      filling values, or by default fills with 0.
 * @returns {T[][][]} A 3D array.
 */
function arr3d(width, height, fill) {
    if (typeof fill === 'function') return new Array(width).fill(new Array(height).fill(new Array(depth).fill(fill())));
    else if (fill) return new Array(width).fill(new Array(height).fill(new Array(depth).fill(fill)));
    else return new Array(width).fill(new Array(height).fill(new Array(depth).fill(0)));
}

/**
 * @description Mergesort an array.
 * @param {readonly T[]} arr The array to be sorted.
 * @param {(first: T, second: T) => boolean} cmp A compare function. Returns 
 *      true to put the first item in the front. False otherwise.
 * @returns {T[]} A new sorted array.
 */
function mergesort(arr, cmp) {
    
    const merge = (left, right) => {
        const arr = [];
        // Break out of loop if any one of the array gets empty
        while (left.length && right.length) {
            // Pick the smaller among the smallest element of left and right sub arrays 
            if (cmp(left[0], right[0])) {
                arr.push(left.shift())
            } else {
                arr.push(right.shift())
            }
        }
        // (in case we didn't go through the entire left or right array)
        return [ ...arr, ...left, ...right ];
    };
    
    const half = arr.length / 2;

    // Base case or terminating case
    if(arr.length < 2){
        return arr;
    }

    const left = arr.splice(0, half);
    return merge(mergesort(left), mergesort(arr));
}

/**
 * @description Iterate the given node using DFS.
 * @param {T} node The root node.
 * @param {string} childProp The children property name in string.
 * @param {(node: T) => void} visitor A visitor function applies to each children node.
 * @returns {void}
 */
function dfs(node, childProp, visitor) {
    visitor(node);
    for (const child of node[childProp]) {
        visitor(child);
    }
}

/**
 * @description Iterate the given node using BFS.
 * @param {T} node The root node.
 * @param {string} childProp The children property name in string.
 * @param {(node: T) => void} visitor A visitor function applies to each children node.
 * @returns {void}
 */
function bfs(node, childProp, visitor) {
    const queue = [node];

    while (queue.length) {
        const node = queue.shift();
        visitor(node);
        for (const child of node[childProp]) {
            queue.push(child);
        }
    }
}
