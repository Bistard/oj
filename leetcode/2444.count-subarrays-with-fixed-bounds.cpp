#ifndef __utility__
#define __utility__

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

#ifndef __constants__
#define __constants__

const double PI = acos(-1);
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int directions8[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
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

typedef unordered_map<int, int> mii;
typedef unordered_map<char, char> mcc;
typedef unordered_map<int, string> mis;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, string> mss;
#define umap unordered_map

// bit && number
#define BIT(x, i) (x & (1 << i)) // select the bit at the position i of x. eg: BIT(5, 0) => 1; BIT(5, 2) => 4;
#define LOWBIT(x) ((x) & ((x) ^ ((x) - 1))) // get the lowest bit of x
#define SETMAX(a, b) (a) = max((a), (b))
#define SETMIN(a, b) (a) = min((a), (b))
#define CLAMP(n, min, max) ((n <= min) ? min : (n >= max ? max : n))
#define SQ(n) ((n) * (n))
#define INTMAX __INT_MAX__
#define INTMIN (-INTMAX - 1)
#define SUM(arr) (reduce(arr.begin(), arr.end()))

// array
#define arr2d(v, n, m, fill) vvi v((n), vi((m), (fill)))
#define arr2dc(v, n, m, fill) vvc v((n), vc((m), (fill)))
#define arr2db(v, n, m, fill) vvb v((n), vb((m), (fill)))
#define charmap(map, size, fill) char map[size] = { fill };
#define fi first
#define se second
#define mp make_pair
#define pb push_back

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
ostream &operator<<(ostream &out, const stack<T> &s) {
    out << "[";
    
    if (!s.empty()) {
        stack<T> copy = s;
        out << copy.top();
        copy.pop();

        while (!copy.empty()) {
            out << ", ";
            auto top = copy.top();
            out << top;
            copy.pop();
        }
    }

    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const queue<T> &q) {
    out << "[";
    
    if (!q.empty()) {
        queue<T> copy = q;
        out << copy.front();
        copy.pop();

        while (!copy.empty()) {
            out << ", ";
            auto front = copy.front();
            out << front;
            copy.pop();
        }
    }

    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const priority_queue<T> &pq) {
    return __print_iterable(out, pq); // BUG
}

template<typename T>
ostream &operator<<(ostream &out, const deque<T> &deq) {
    return __print_iterable(out, deq); // BUG
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

// tag: O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        const int n = nums.size();
        long long cnt = 0;
        
        long long start = 0;
        long long prevMin = -1, prevMax = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                prevMin = -1, prevMax = -1;
                start = i + 1;
                continue;
            }

            if (nums[i] == minK) {
                prevMin = i;
            }

            if (nums[i] == maxK) {
                prevMax = i;
            }

            if (prevMin != -1 && prevMax != -1) {
                cnt += min(prevMin, prevMax) - start + 1;
            }
        }

        return cnt;
    }
};

// tag: DP (2D)
class TLE {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        const int n = nums.size();
        int cnt = 0;
        
        // dp[i][j]: the {minVal, maxVal} in the range [i, j]
        vector<vector<pii>> dp(n, vpii(n, {0, 0}));
        REPEAT(i, n) {
            dp[i][i] = make_pair(nums[i], nums[i]);
            if (minK == nums[i] && nums[i] == maxK) {
                cnt++;
            }
        }
        
        REPEAT(i, n) {
            REPEAT(j, n - i) {
                auto [x, y] = make_pair(j, j + i);
                
                if (x == y) continue;
                if (x == n - 1) continue;

                auto [leftMin, leftMax] = dp[x][y - 1];
                auto [bottMin, bottMax] = dp[x + 1][y];

                dp[x][y] = make_pair(min(leftMin, bottMin), max(leftMax, bottMax));
                auto [minVal, maxVal] = dp[x][y];
                
                if (minK == minVal && maxVal == maxK) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


class Solution {
public:
    long long countSubarrays(vector<int>& a, int m, int M) {
        long long ans = 0, cur = 0;
        
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] >= m && a[i] <= M) ++cur;
            else {
                ans += cur * (cur + 1) / 2;
                cur = 0;
            }
        }
        ans += cur * (cur + 1) / 2;
        
        cur = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] > m && a[i] < M) ++cur;
            else {
                ans += cur * (cur + 1) / 2;
                cur = 0;
            }
        }
        ans += cur * (cur + 1) / 2;
        
        cur = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] >= m && a[i] < M) ++cur;
            else {
                ans -= cur * (cur + 1) / 2;
                cur = 0;
            }
        }
        ans -= cur * (cur + 1) / 2;
        
        cur = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] > m && a[i] <= M) ++cur;
            else {
                ans -= cur * (cur + 1) / 2;
                cur = 0;
            }
        }
        ans -= cur * (cur + 1) / 2;
        
        return ans;
    }
};