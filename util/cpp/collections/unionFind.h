#pragma once

#include "../utility.h"

class UnionFind {

public:
    UnionFind(int n): _parents { vi(n) } {
        REPEAT(i, n) {
            _parents[i] = i;
        }
    }

    int find(int x) {
        if (_parents[x] != x) {
            _parents[x] = find(_parents[x]);
        }
        return _parents[x];
    }

    void unions(int x, int y) {
        _rootx = find(x);
        _rooty = find(y);
        _parents[_rootx] = _rooty;
    }

public:
    vi _parents;
    int _rootx, _rooty;
};
