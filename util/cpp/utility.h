#include <iostream>
#include <map>
#include <hash_map>
#include <unordered_map>

template<typename T, template<typename E, typename ALLOC=std::allocator<E>> class Container>
std::ostream& operator<<(std::ostream &o, const Container<T> &container)
{
    typename Container<T>::const_iterator beg = container.begin();
    o << "[";
    while (beg != container.end()) o << " " << *beg++;
    o << " ]";
    return o;
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &pair)
{
    out << "[" << pair.first << ", " << pair.second << "]" << ' ';
    return out;
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &map)
{
    out << "{";
    for (const std::pair<const K, V> &pair : map) {
        out << pair << ' ';
    }
    out << "}";
    return out;
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::hash_map<K, V> &map)
{
    out << "{";
    for (const std::pair<const K, V> &pair : map) {
        out << pair << ' ';
    }
    out << "}";
    return out;
}

template<typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<K, V> &map)
{
    out << "{";
    for (const std::pair<const K, V> &pair : map) {
        out << pair << ' ';
    }
    out << "}";
    return out;
}
