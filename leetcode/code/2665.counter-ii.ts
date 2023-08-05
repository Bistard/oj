type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let num = init;
    return <ReturnObj>{
        increment: () => ++num,
        decrement: () => --num,
        reset: () => {
            num = init;
            return num;
        },
    };
};