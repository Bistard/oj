/*
 * @lc app=leetcode id=743 lang=ts
 *
 * [743] Network Delay Time
 */

// @lc code=start
function networkDelayTime(times: number[][], n: number, k: number): number {
    const graph = new Map<number, [number, number][]>();
    for (const [u, v, w] of times) {
        if (!graph.has(u)) {
            graph.set(u, []);
        }
        graph.get(u)!.push([v, w]);
    }

    const minTimeReachEveryNode = new Array<number>(n).fill(Number.POSITIVE_INFINITY);
    minTimeReachEveryNode[k - 1] = 0;
    const pq: [number, number][] = [[0, k]]; // [distance, node]

    while (pq.length) {
        pq.sort((a, b) => a[0] - b[0]);
        const [currTime, node] = pq.shift()!;

        for (const [next, weight] of graph.get(node) ?? []) {
            const reachChildTime = minTimeReachEveryNode[node - 1] + weight;
            if (reachChildTime < minTimeReachEveryNode[next - 1]) {
                minTimeReachEveryNode[next - 1] = reachChildTime;
                pq.push([reachChildTime, next]);
            }
        }
    }

    const maxTime = Math.max(...minTimeReachEveryNode);
    return maxTime === Number.POSITIVE_INFINITY ? -1 : maxTime;
}

// @lc code=end

