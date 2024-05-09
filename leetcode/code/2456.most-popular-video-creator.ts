/*
 * @lc app=leetcode id=2456 lang=ts
 *
 * [2456] Most Popular Video Creator
 */

// @lc code=start
function mostPopularCreator(creators: string[], ids: string[], views: number[]): string[][] {
    const pop = new Map<string, [most: [id: string[], val: number], sum: number]>();
    const n = creators.length;
    for (let i = 0; i < n; i++) {
        const c = creators[i];
        const id = ids[i];
        const view = views[i];

        let metadata = pop.get(c);
        if (!metadata) {
            metadata = [[[id], view], view];
            pop.set(c, metadata);
            continue;
        }

        metadata[1] += view;
        if (view > metadata[0][1]) {
            metadata[0][0] = [id];
            metadata[0][1] = view;
        } else if (view === metadata[0][1]) {
            metadata[0][0].push(id);
        }
    }

    let maxView = 0;
    let maxCreators: [string, any][] = [];
    
    for (const [creator, [most, sum]] of pop.entries()) {
        if (sum > maxView) {
            maxCreators = [[creator, most]];
            maxView = sum;
        } else if (sum === maxView) {
            maxCreators.push([creator, most]);
        }
    }

    const ans: [string, string][] = [];
    maxCreators.forEach(([creator, [id, val]]) => {
        ans.push([creator, id.sort().at(0)]);
    });

    return ans;
};
// @lc code=end

