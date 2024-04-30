function trap(height: number[]): number {
    let totalSpace = findTotalSpace(height);

    const forward = findConsecutive(true, height);
    const backward = findConsecutive(false, height);

    totalSpace -= removeEmptySpace(forward, each => each.i);
    totalSpace -= removeEmptySpace(backward, each => (height.length - 1) - each.i);

    return totalSpace;
};

interface IEach { i: number, h: number };

function findTotalSpace(height: number[]): number {
    const maxHeight = Math.max(...height);
    
    let space = 0;
    for (let i = 0; i < height.length; i++) {
        const h = height[i]!;

        space += (maxHeight - h);
    }

    return space;
}

function findConsecutive(isForward: boolean, height: number[]): IEach[] {
    const consecutive: { i: number, h: number }[] = [];
    let curr = 0;

    const indexInit: number = isForward
        ? 0
        : height.length - 1;
    const indexCk: (i: number) => boolean = isForward 
        ? i => i < height.length 
        : i => i >= 0;
    const indexOp: (i: number) => number  = isForward 
        ? idx => i++ 
        : idx => i--;
    
    let i = 0;
    for (i = indexInit; indexCk(i); indexOp(i)) {
        const h = height[i];
        if (h > curr) {
            consecutive.push({ i, h });
            curr = h;
        }
    }

    return consecutive;
}

function removeEmptySpace(consecutive: IEach[], getWidth: (each: IEach) => number): number {
    let emptySpace = 0;
    
    for (let i = 0; i < consecutive.length; i++) {
        const each = consecutive[i]!;
        const beforeEach = consecutive[i - 1]!;

        const width = getWidth(each);

        if (i === 0) {
            emptySpace += (width * each.h);
            continue;
        }

        emptySpace += width * (each.h - beforeEach.h);
    }

    return emptySpace;
}