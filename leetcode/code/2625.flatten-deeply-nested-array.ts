type MultiDimensionalArray = (number | MultiDimensionalArray)[];

// iteration
var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    let array = arr;
    
    for (let i = 0; i < n; i++) {
        const flatten: MultiDimensionalArray = [];
        for (const element of array) {
            if (!Array.isArray(element)) {
                flatten.push(element);
                continue;
            }

            for (const subElement of element) {
                flatten.push(subElement);
            }
        }

        array = flatten;
        if (array.length === 0) {
            break;
        }
    }

    return array;
};

// recursive (MLE)
var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if (n === 0) {
        return arr;
    }
    
    const flatten: MultiDimensionalArray = [];
    for (const element of arr) {
        if (!Array.isArray(element)) {
            flatten.push(element);
            continue;
        }

        for (const subElement of element) {
            flatten.push(subElement);
        }
    }

    return flat(flatten, n - 1);
};