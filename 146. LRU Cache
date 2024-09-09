#include <unordered_map>
#include <list>
#include <utility> // For std::pair

class LRUCache {
private:
    int capacity;
    unordered_map<int,list<pair<int, int>>::iterator> map;
    list<pair<int, int>> cache;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1; // Key not found

        // Move the accessed item to the front (most recently used)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second; // Return the value
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update the value and move the item to the front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
        } else {
            // If the cache is full, remove the least recently used item
            if (cache.size() == capacity) {
                int old_key = cache.back().first;
                cache.pop_back();
                map.erase(old_key);
            }
            // Insert the new key-value pair
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
