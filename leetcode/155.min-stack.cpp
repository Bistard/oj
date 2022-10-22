/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

// tag: consider each node has a minimum value.
class MinStack {
private:
    stack<pair<int, int>> s;
public:
    MinStack() {}
    
    void push(int val) {
        if (!s.empty()) {
            auto [prevVal, currMin] = s.top();
            s.push({val, min(val, currMin)});
        } else {
            s.push({val, val});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
// @lc code=end

