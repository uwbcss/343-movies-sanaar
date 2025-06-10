#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <unordered_map>

template <typename K, typename V>
class HashTable {
public:
    void insert(const K& key, V value) {
        table[key] = value;
    }

    V get(const K& key) const {
        auto it = table.find(key);
        if (it != table.end()) return it->second;
        return nullptr;
    }

    bool contains(const K& key) const {
        return table.find(key) != table.end();
    }

private:
    std::unordered_map<K, V> table;
};

#endif