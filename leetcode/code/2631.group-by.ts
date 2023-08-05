declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function <T>(fn: (item: T) => string): Record<string, T[]> {
    const result = {};

    for (const element of this) {
        const key = fn(element);
        result[fn(element)] ||= [];
        result[key].push(element);
    }

    return result;
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */