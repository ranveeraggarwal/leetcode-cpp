#include "stdafx.h"

class LRUCache
{
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> store;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        int value = -1;
        auto map_it = store.find(key);
        if (map_it != store.end())
        {
            auto list_it = map_it->second;
            value = list_it->second;
            cache.erase(list_it);
            cache.push_front(make_pair(key, value));
            store[key] = cache.begin();
        }
        return value;
    }

    void put(int key, int value)
    {
        if (get(key) == -1)
        {
            if (!capacity)
            {
                auto it = cache.end();
                it--;
                store.erase(it->first);
                cache.pop_back();
                capacity++;
            }
            cache.push_front(make_pair(key, value));
            store[key] = cache.begin();
            capacity--;
        }
        else
        {
            store[key]->second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */