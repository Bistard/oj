/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, double> tiid;
#define SQ(n) ((n) * (n))

//tag: minheap; time: O(nlogn);
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // min heap
        auto compareFn = [](const tiid &a, const tiid &b) -> bool {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<tiid, vector<tiid>, decltype(compareFn)> pq(compareFn);
        
        // push every points into the heap
        for (auto &point : points) {
            pq.push(make_tuple(point[0], point[1], sqrt(SQ(point[0]) + SQ(point[1]))));
        }

        // find the k closest points
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            auto [x, y, val] = pq.top();
            result.push_back(vector<int> {x, y});
            pq.pop();
        }

        return result;
    }
};
// @lc code=end

