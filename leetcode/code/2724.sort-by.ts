
// self-implement
var sortBy = (arr: any[], fn: (ele: any) => number): any[] => {
    
    function mergeSort(arr: any[]): any[] {
        if (arr.length <= 1) {
            return arr;
        }
    
        const middle = Math.floor(arr.length / 2);
        const left = mergeSort(arr.slice(0, middle));
        const right = mergeSort(arr.slice(middle));
    
        return merge(left, right);
    }

    function merge(left: any[], right: any[]): any[] {
        let result: any[] = [];
        let i = 0, j = 0;

        while (i < left.length && j < right.length) {
            if (fn(left[i]) < fn(right[j])) {
                result.push(left[i]);
                i++;
            } else {
                result.push(right[j]);
                j++;
            }
        }

        return result.concat(left.slice(i))
                     .concat(right.slice(j));
    }

    return mergeSort(arr);
};

// built-in
var sortBy = (arr: any[], fn: (ele: any) => number): any[] => {
    return arr.sort((a, b) => fn(a) - fn(b));
};