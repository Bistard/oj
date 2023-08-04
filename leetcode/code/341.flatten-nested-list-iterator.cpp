/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// @lc code=start

class NestedIterator {
private:
    stack<vector<NestedInteger>::const_iterator> sBegins;
    stack<vector<NestedInteger>::const_iterator> sEnds;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        sBegins.push(nestedList.begin());
        sEnds.push(nestedList.end());
    }
    
    int next() {
        auto &it = sBegins.top();
        auto &val = *it;
        it++;
        return val.getInteger();
    }
    
    bool hasNext() {
        if (sBegins.empty()) {
            return false;
        }

        /**
         * The current list iteration is completed and we should go upwards 
         * (stack pop).
         */
        if (sBegins.top() == sEnds.top()) {
            sBegins.pop();
            sEnds.pop();
            return this->hasNext();
        }

        // the current list iteration is not completed.
        auto &it = sBegins.top();
        auto &numberOrList = *it;
        
        // The iterator points to a number, we do not move it and return true.
        if (numberOrList.isInteger()) {
            return true;
        } 
        /**
         * The iterator points to a list, move the current vector iterator to 
         * next one and push the new list iterator pairs.
         */
        else {
            ++it;
            auto &list = numberOrList.getList();
            sBegins.push(list.begin());
            sEnds.push(list.end());
            return this->hasNext();
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

