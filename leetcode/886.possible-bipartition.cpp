/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start

#ifndef __utility__
#define __utility__

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

#ifndef __constants__
#define __constants__

const double PI = acos(-1);
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
#endif

#ifndef __marcos__
#define __marcos__

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
#define arr2d(v, n, m, fill) vvi v((n), vi((m), (fill)))
#define arr2dc(v, n, m, fill) vvc v((n), vc((m), (fill)))

typedef unordered_map<int, int> mii;
typedef unordered_map<int, string> mis;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, string> mss;
#define umap unordered_map

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// bit && number
#define BIT(x, i) (x & (1 << i)) // select the bit at the position i of x. eg: BIT(5, 0) => 1; BIT(5, 2) => 4;
#define LOWBIT(x) ((x) & ((x) ^ ((x) - 1))) // get the lowest bit of x
#define SETMAX(a, b) (a) = max((a), (b))
#define SETMIN(a, b) (a) = min((a), (b))
#define CLAMP(n, min, max) ((n <= min) ? min : (n >= max ? max : n))

// boundary
#define IN(i, l, r) (((l) < (i)) && ((i) < (r)))
#define INL(i, l, r) (((l) <= (i)) && ((i) < (r)))
#define INR(i, l, r) (((l) < (i)) && ((i) <= (r)))
#define INLR(i, l, r) (((l) <= (i)) && ((i) <= (r)))

// iterator
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define HAS(c, v) ((c).find(v) != (c).end())
#define WHILEIT(it, c) auto it = (c).begin(); while (it != (c).end())

// loop
#define FOR(i, l, r) for (int (i) = (l); (i) < (r); ++(i))
#define FORE(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define FFOR(i, l, r) for (int (i) = (l); (i) > (r); --(i))
#define FFORE(i, l, r) for (int (i) = (l); (i) >= (r); --(i))
#define FOREACH(v, c) for (auto &(v) : (c))
#define REPEAT(i, n) FOR(i, 0, n)
#define REPEATN(i, n) FORE(i, 1, n)
#endif

#ifndef __pretty_print__
#define __pretty_print__

#define IOS ios_base::sync_with_stdio(0) // to synchronize the input of cin and scanf
#define BREAK cout << "===========" << endl
#define VALUE(x) cout << "The value of " << #x << " is " << x << endl

template<typename K, typename V>
ostream &operator<<(ostream &out, const pair<K, V> &pair)
{
    out << "<" << pair.first << ", " << pair.second << ">";
    return out;
}

template<typename T>
static ostream &__print_iterable(ostream &out, const T &container) 
{
    auto it = container.begin();
    out << "{ " << *it++;
    while (it != container.end()) {
        out << ", " << *it++;
    }
    out << " }";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &vec) {
    return __print_iterable(out, vec);
}

template<typename T, size_t Size>
ostream &operator<<(ostream &out, const array<T, Size> &arr) {
    return __print_iterable(out, arr);
}

template<typename T>
ostream &operator<<(ostream &out, const set<T> &set) {
    return __print_iterable(out, set);
}

template<typename K, typename V>
ostream &operator<<(ostream &out, const map<K, V> &map) {
    return __print_iterable(out, map);
}

template<typename K, typename V>
ostream &operator<<(ostream &out, const unordered_map<K, V> &map) {
    return __print_iterable(out, map);
}
#endif

#endif

// tag: union-find
class Solution {
private:
    int a = 0, b = 0;
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vi p(n + 1);
        FORE(i, 0, n) {
            p[i] = i;
        }

        // build graphs
        vi relations(n + 1, 0);
        FOREACH(dislike, dislikes) {
            a = dislike[0];
            b = dislike[1];

            if (!relations[a]) {
                relations[a] = b;
            }
            if (!relations[b]) {
                relations[b] = a;
            }
        }

        FOREACH(dislike, dislikes) {
            a = dislike[0];
            b = dislike[1];

            if (find(p, a) == find(p, b)) {
                return false;
            }

            unions(p, a, relations[b]);
            unions(p, b, relations[a]);
        }

        return true;
    }

    int find(vi &parents, int x) {
        if (parents[x] != x) {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    void unions(vi &parents, int x, int y) {
        const int rootx = find(parents, x);
        const int rooty = find(parents, y);
        parents[rootx] = rooty;
    }
};

// tag: DFS
class DFS {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vb visited(n + 1, false);
        vb groups(n + 1, false);

        groups[dislikes[0][0]] = true; // set initially to group 1

        FOREACH(dislike, dislikes) {
            if (groups[dislike[0]] == groups[dislike[1]]) {
                return false;
            }
            
            groups[dislike[1]] = groups[dislike[0]] ^ 1;
        }

        return true;
    }
};
// @lc code=end

