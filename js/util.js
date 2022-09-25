
function repeat(round, fn) {
    for (let i = 0; i < round; i++) fn(i);
}

function arr2d(width, height, fill) {
    return new Array(width).fill(new Array(height).fill(fill ?? 0));
}

function arr3d(width, height, fill) {
    return new Array(width).fill(new Array(width).fill(new Array(height).fill(fill ?? 0)));
}

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