/*
Number: 460
Topic: LFU Cache
Date: 2021/11/29
Rate: Hard
https://leetcode.com/problems/lfu-cache/

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

    * LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    * int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    * void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

Constraints:
    * 0 <= capacity <= 104
    * 0 <= key <= 105
    * 0 <= value <= 109
    * At most 2 * 105 calls will be made to get and put.
*/
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LFUCache {
   private:
    int _minFrequency;
    int _capacity;
    int _size;
    unordered_map<int, list<int>> _caches;
    unordered_map<int, tuple<int, int, list<int>::iterator>> _dict;

    void promote(int key) {
        tuple<int, int, list<int>::iterator> targetTuple = _dict[key];
        int value = std::get<0>(targetTuple);
        int freq = std::get<1>(targetTuple);
        list<int>::iterator pointer = std::get<2>(targetTuple);

        // delete origin
        _caches[freq].erase(pointer);

        // put it to frequency + 1, push front
        _caches[freq + 1].push_front(key);
        // update minFreq
        if (_caches[_minFrequency].empty())
            _minFrequency += 1;
        // update dict
        _dict[key] = make_tuple(value, freq + 1, _caches[freq + 1].begin());
    }

   public:
    LFUCache(int capacity) {
        /*
        Actions:
            - get:
                - check if the key present
                    - promote the key
                        - promote frequency
                        - promote recency
                    - return value
                - throw exception

            - put:
                - check if the key present
                    - update the value
                    - promote the key
                        - promote frequency
                        - promote recency
                - evict excess
                    - get minFrequency cache, pop back
                - add new value
                    - put it to frequency == 1 cache, push front

            - promote:
                - delete the origin element
                - put it to frequency + 1, push front

        Data Strcuture:
            - map (int freq : list cache)
                - list cache(key) : most recent in the head, least in the tail
            - map (int key : {int value, int freq, iterator node})
        */
        _capacity = capacity;
        _size = 0;
        _minFrequency = 0;
    }

    int get(int key) {
        if (_dict.count(key) == 0)
            return -1;
        promote(key);
        return std::get<0>(_dict[key]);
    }

    void put(int key, int value) {
        if (_capacity == 0)
            return;

        // update the key
        if (_dict.count(key) == 1) {
            promote(key);
            auto targetTuple = _dict[key];
            _dict[key] = make_tuple(value, std::get<1>(targetTuple), std::get<2>(targetTuple));
        }

        // add new element
        else {
            // evict excess
            if (_size == _capacity) {
                _dict.erase(_caches[_minFrequency].back());
                _caches[_minFrequency].pop_back();
                _size -= 1;
            }
            _caches[1].push_front(key);
            _dict[key] = make_tuple(value, 1, _caches[1].begin());
            _size += 1;
            _minFrequency = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */