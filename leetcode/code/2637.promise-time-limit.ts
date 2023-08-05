type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
	return async function(...args) {
        let resolve, reject;
        const promise = new Promise((res, rej) => {
            resolve = res;
            reject = rej;
        })

        setTimeout(() => reject('Time Limit Exceeded'), t);
        fn(...args)
        .then((res) => resolve(res))
        .catch(err => reject(err));
        
        return promise;
    };
};