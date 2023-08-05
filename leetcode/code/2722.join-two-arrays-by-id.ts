function join(arr1: any[], arr2: any[]): any[] {
    const result = {};

    for (const element of arr1) {
        result[element.id] = element;
    }

    for (const element of arr2) {
        if (result[element.id]) {
            for (const key in element) {
                result[element.id][key] = element[key];
            }
        } else {
            result[element.id] = element;
        }
    }

    return Object.values(result);
};