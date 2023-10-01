#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

// tag: stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        // using stack
        stack<int> stk;
        for (auto &aster : asteroids) {
            checkCollsion(stk, aster);
        }

        // to vector
        const int size = stk.size();
        vector<int> vec(size);
        for(int i = size - 1; i >= 0; i--) {
            vec[i] = stk.top();
            stk.pop();
        }

        return vec;
    }

    void checkCollsion(stack<int> &stk, int aster) {
        if (stk.empty()) {
            stk.push(aster);
            return;
        }

        const int curr = stk.top();
        
        // same dir, nothing happens
        if ((curr ^ aster) >= 0) {
            stk.push(aster);
            return;
        }

        // opposite dir
        if (curr < 0 && aster > 0) {
            stk.push(aster);
            return;
        }

        /** 
         * facing to each other, check collision.
         */
        
        if (curr < -aster) {
            stk.pop();
            checkCollsion(stk, aster); // continue collision
            return;
        }

        if (curr == -aster) {
            stk.pop();
            return;
        }

        // curr > -aster
        return;
    }
};