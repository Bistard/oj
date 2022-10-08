/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start

#ifndef __utility__
#define __utility__

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

#ifndef __constants__
#define __constants__

const double PI = acos(-1);
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
#endif

#ifndef __marcos__
#define __marcos__

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

typedef set<int> si;

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
#define charmap(map, size, fill) char map[size] = { fill };

typedef unordered_map<int, int> mii;
typedef unordered_map<char, char> mcc;
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
#define SQ(n) ((n) * (n))

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
#define VALUE(x) cout << "The value of \"" << #x << "\" is: " << x << endl

template<typename K, typename V>
ostream &operator<<(ostream &out, const pair<K, V> &pair)
{
    out << "<" << pair.first << ", " << pair.second << ">";
    return out;
}

template<typename T>
static inline ostream &__print_iterable(ostream &out, const T &container) 
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

template<typename T>
ostream &operator<<(ostream &out, const stack<T> &stack) {
    return __print_iterable(out, stack);
}

template<typename T>
ostream &operator<<(ostream &out, const queue<T> &queue) {
    return __print_iterable(out, queue);
}

template<typename T>
ostream &operator<<(ostream &out, const priority_queue<T> &pq) {
    return __print_iterable(out, pq);
}

template<typename T>
ostream &operator<<(ostream &out, const deque<T> &deq) {
    return __print_iterable(out, deq);
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

// tag: BFS
class Solution {
private:
    int n, m;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        arr2dc(pacific, n, m, false);
        arr2dc(atlantic, n, m, false);
        
        vvi result;
        queue<pii> q1, q2;

        // pacific ocean edge
        FOR(x, 0, n) q1.push({x, 0});
        FOR(y, 0, m) q1.push({0, y});
        bfs(q1, pacific, heights);

        // atlantic ocean edge
        FOR(x, 0, n) q2.push({x, m - 1});
        FOR(y, 0, m) q2.push({n - 1, y});
        bfs(q2, atlantic, heights);


        // REVIEW: I believe this part can be optimzied out
        REPEAT(i, n) {
            REPEAT(j, m) {
                if (pacific[i][j] == 1 && pacific[i][j] == atlantic[i][j]) {
                    result.emplace_back(vi {i, j});
                }
            }
        }

        return result;
    }

    void bfs(queue<pii> &q, vvc &visited, vvi &heights) {

        while (!q.empty()) {
            
            auto [x, y] = q.front();
            q.pop();
            visited[x][y] = true;

            FOREACH(dir, directions) {
                int newx = x + dir[0];
                int newy = y + dir[1];

                if (!INL(newx, 0, n) || !INL(newy, 0, m) || visited[newx][newy] || !(heights[newx][newy] >= heights[x][y])) {
                    continue;
                }

                visited[newx][newy] = true;
                q.push({newx, newy});
            }
        }
    }
};
// @lc code=end

