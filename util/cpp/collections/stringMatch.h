#pragma once

#include "../utility.h"

class StringMatchByKmp {
public:
    int match(const string &s, const string &pattern) {
        const int n = s.length();
        const int m = pattern.length();
        
        // lps
        int state = 0;
        int i = 1;
        vi lps(m, 0);
        while (i < m) {
            if (pattern[i] == pattern[state]) {
                lps[i] = state + 1;
                state++;
                i++;
            }
            else {
                if (state == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    state = lps[state - 1];
                }
            }
        }
        
        // kmp
        i = 0;
        state = 0;
        while (i < n) {
            if (s[i] == pattern[state]) {
                i++;
                state++;
            } else {
                if (state == 0) {
                    i++;
                } else {
                    state = lps[state - 1];
                }
            }

            if (state == m) {
                return i - m;
            }
        }
        
        return -1;
    }
};
