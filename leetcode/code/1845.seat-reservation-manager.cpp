/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

// tag: bitset; space: O(1);
class SeatManager {
private:
    bitset<(int)1e5> bit;
public:
    SeatManager(int n) {
        bit.set();
    }
    
    int reserve() {
        int seat = bit._Find_first();
        bit.set(seat, false);
        return seat + 1;
    }
    
    void unreserve(int seatNumber) {
        bit.set(seatNumber - 1, true);
    }
};

// tag: minheap; space: O(n);
class SeatManagerUsingMinheap {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManagerUsingMinheap(int n) {
        for (int seat = 1; seat <= n; seat++) {
            pq.push(seat);
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end

