#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

class RecentCounter {
private:
    queue<int> recentReq;
public:
    RecentCounter() {}
    
    int ping(int t) {
        while (!recentReq.empty() && (t - recentReq.front() > 3000)) {
            recentReq.pop();
        }
        recentReq.push(t);

        return recentReq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */