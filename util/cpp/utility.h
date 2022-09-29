#ifndef __oi_utility__
#define __oi_utility__

#include <bits/stdc++.h> // Include every standard library

#ifndef __constants__
#define __constants__

const double PI = acos(-1);
const int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
const int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
#endif

#ifndef __marcos__
#define __marcos__

typedef std::pair<int, int> pii;
typedef std::pair<std::string, std::string> pss;

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#endif

#ifndef __pretty_print__
#define __pretty_print__

#define BREAK std::cout << "===========" << std::endl
#define VALUE(x) std::cout << "The value of " << #x << " is " << x << std::endl

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &pair)
{
    out << "<" << pair.first << ", " << pair.second << ">";
    return out;
}

template<typename T>
static std::ostream &__print_iterable(std::ostream &out, const T &container) 
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
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    return __print_iterable(out, vec);
}

template<typename T, size_t Size>
std::ostream &operator<<(std::ostream &out, const std::array<T, Size> &arr) {
    return __print_iterable(out, arr);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &set) {
    return __print_iterable(out, set);
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &map) {
    return __print_iterable(out, map);
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<K, V> &map) {
    return __print_iterable(out, map);
}
#endif

#endif