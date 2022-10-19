/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// time: O(n);
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> incoming(n + 1, 0);
        vector<int> outcoming(n + 1, 0);

        for (auto &edge : trust) {
            int p1 = edge[0];
            int p2 = edge[1];

            outcoming[p1]++;
            incoming[p2]++;
        }

        int townJudge = 0;
        int trustNobody = 0;
        int beingTrustedByEveryone = 0;
        for (int p = 1; p <= n; p++) {
            if (outcoming[p] == 0) {
                townJudge = p;
                trustNobody++;
            }
            if (incoming[p] == n - 1) {
                townJudge = p;
                beingTrustedByEveryone++;
            }
        }

        if (beingTrustedByEveryone == 1 && trustNobody == 1) {
            return townJudge;
        } else {
            return -1;
        }
    }
};
// @lc code=end

