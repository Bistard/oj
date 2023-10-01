#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

// tag: stack
class Solution {
public:
    string removeStars(string s) {
        string stk;

        for (auto &c : s) {
            if (c != '*') {
                stk += c;
                continue;
            }
            
            stk.pop_back();
        }

        return stk;
    }
};