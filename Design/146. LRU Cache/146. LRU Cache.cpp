/*
Number: 146
Topic: LRU Cache
Date: 2021/11/28
Rate: Medium
https://leetcode.com/problems/lru-cache/

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
    * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    * int get(int key) Return the value of the key if the key exists, otherwise return -1.
    * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Constraints:
    * 1 <= capacity <= 3000
    * 0 <= key <= 104
    * 0 <= value <= 105
    * At most 2 * 105 calls will be made to get and put.
*/

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache {
   private:
    list<pair<int, int>> freqLink;
    unordered_map<int, list<pair<int, int>>::iterator> accessPort;
    int size;
    int capacity;

   public:
    LRUCache(int capacity) {
        /*
        - (Data Structure) Store the frequency  => Linkedlist
            - Requirement:
                - access the least frequency element as soon as possible (in order) => most frequent at the head / least at the tail
                - update the frequency in as soon as possible => O(1) supported by Linkedlist
                - add a new pair as soon as possible => O(1) supported by Linkedlist
        - (Data Structure) Random access => Hashmap
            - Requirement:
                - random access any pair as soon as possible => O(1)
                - access linked with frequency => key : element in the Linkedlist

        - Actions:
            - get
                - check if the key present
                - delete origin
                - add the element in the head
            - put
                - check if the key present
                - delete the origin if present
                - evict excess
                - add the element in the head  
        */
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        // check ...
        if (capacity == 0 || size == 0 || accessPort.count(key) == 0)
            return -1;

        // delete ...
        auto targetPointer = accessPort[key];
        pair<int, int> targetPair = *targetPointer;
        freqLink.erase(targetPointer);

        // add ...
        freqLink.push_front(targetPair);
        accessPort[key] = freqLink.begin();

        return targetPair.second;
    }

    void put(int key, int value) {
        // check
        if (capacity == 0)
            return;

        // delete origin ...
        if (accessPort.count(key)) {
            freqLink.erase(accessPort[key]);
            size -= 1;
        }
        // add ...
        freqLink.push_front(make_pair(key, value));
        accessPort[key] = freqLink.begin();
        size += 1;

        // evict excess ...
        if (size > capacity) {
            accessPort.erase(freqLink.back().first);
            freqLink.pop_back();
            size -= 1;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */