type F = (...p: any[]) => any

function debounce(fn: F, t: number): F {
    let cancelToken: any;
    let inWindow: boolean = false;
    
    const onSchedule = (...args: any) => {
        return setTimeout(() => {
            fn(...args);
            inWindow = false;
        }, t);
    };

    return function(...args) {
        
        if (!inWindow) {
            cancelToken = onSchedule(...args);
            inWindow = true;
            return;
        }

        clearTimeout(cancelToken);
        cancelToken = onSchedule(...args);
    };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */