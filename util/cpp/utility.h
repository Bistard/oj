#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

// #region 1

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
