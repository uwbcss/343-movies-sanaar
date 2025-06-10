#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class HashTable {
public:
    explicit HashTable(int size = 101) : table(size) {}

    void insert(const Key& key, Value value) {
        int index = hash(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
    }
        }
        table[index].emplace_back(key, value);
    }

    Value get(const Key& key) const {
        int index = hash(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
              return kv.second;
      }
        }
        throw std::runtime_error("Key not found");
  }

    bool contains(const Key& key) const {
    int index = hash(key);
    return std::any_of(
        table[index].begin(), table[index].end(),
        [&key](const std::pair<Key, Value>& kv) { return kv.first == key; });
  }

private:
    std::vector<std::list<std::pair<Key, Value>>> table;

    int hash(const Key& key) const {
        return std::hash<Key>{}(key) % table.size();
    }
};

#endif
