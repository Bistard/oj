function chunk(arr: any[], size: number): any[][] {
    const chunks: any[] = [];

    let cnt = 0;
    let chunk: any[] = [];
    arr.forEach((ele) => {
        chunk.push(ele);
        cnt = (cnt + 1) % size;
        if (!cnt) {
            chunks.push(chunk);
            chunk = [];
        }
    });

    if (chunk.length) {
        chunks.push(chunk);
    }

    return chunks;
};