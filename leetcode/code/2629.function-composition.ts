type F = (x: number) => number;

function compose(functions: F[]): F {
	const len = functions.length;
    
    return function(x: number) {
        let res = x;

        for (let i = len - 1; i >= 0; i--) {
            res = functions[i]!(res);
        }

        return res;
    };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */