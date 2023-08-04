/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: sorting / hashmap; time: O(n * nlogn);
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> groups;

        for (auto &str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            groups[copy].push_back(str);
        }

        for_each(groups.begin(), groups.end(), [&](auto it) {
            auto [key, value] = it;
            result.push_back(value);
        });

        return result;
    }
};
// @lc code=end

