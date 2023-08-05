async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    const results: T[] = [];

    let resolve, reject;
    const p = new Promise<T[]>((res, rej) => { resolve = res; reject = rej; })

    let finished = 0;
    for (let i = 0; i < functions.length; i++) {
        functions[i]()
        .then(res => {
            finished++;
            results[i] = res;
            if (finished === functions.length) {
                resolve(results);
            }
        })
        .catch(err => reject(err));
    }

    return p;
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */