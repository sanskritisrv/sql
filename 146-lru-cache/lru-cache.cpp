#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<int> dll; // stores keys (most recent at front)
    unordered_map<int, pair<list<int>::iterator, int>> mp; // key -> {iterator, value}

    LRUCache(int cap) {
        capacity = cap;
    }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);      // remove from current position
        dll.push_front(key);           // push to front
        mp[key].first = dll.begin();   // update iterator
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1; // not found
        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (capacity == 0) return; // can't insert anything if capacity is 0

        if (mp.find(key) != mp.end()) {
            // Key already exists -> update value & move to front
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else {
            // Insert new key
            if (dll.size() == capacity) {
                // Remove least recently used key (back)
                int key_to_delete = dll.back();
                dll.pop_back();
                mp.erase(key_to_delete);
            }
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};
