#pragma once

#include "../utility.h"

class UnionFind {

public:

    // initialize a total of n sets, every set contains an element.
    UnionFind(int n): _parents { vi(n) } {
        REPEAT(i, n) {
            _parents[i] = i;
        }
    }

    // find the union of the given element `x`
    int find(int x) {
        if (_parents[x] != x) {
            _parents[x] = find(_parents[x]);
        }
        return _parents[x];
    }

    // union given two elements
    void unions(int x, int y) {
        _rootx = find(x);
        _rooty = find(y);
        _parents[_rootx] = _rooty;
    }

public:
    vi _parents;
    int _rootx, _rooty;
};
