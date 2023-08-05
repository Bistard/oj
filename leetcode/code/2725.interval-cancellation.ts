function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    const cancelToken = setInterval(() => fn(...args), t);
    return () => clearInterval(cancelToken);
};