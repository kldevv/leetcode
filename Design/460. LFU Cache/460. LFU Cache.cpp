/*
Number: 460
Topic: LFU Cache
Date: 2021/9/15
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

class LFUCache {

private:
    unordered_map<int, list<int>> dequeByFreq;
    unordered_map<int, list<int>::iterator> iterUmap;
    unordered_map<int, pair<int, int>> nodeUmap; // key, freq
    int capacity;
    int size;
    int minFreq;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (nodeUmap.count(key) == 0)
            return -1;

        dequeByFreq[nodeUmap[key].second].erase(iterUmap[key]);
        nodeUmap[key].second += 1;
        dequeByFreq[nodeUmap[key].second].push_back(key);
        iterUmap[key] = prev(dequeByFreq[nodeUmap[key].second].end());

        if (dequeByFreq[minFreq].empty())
            minFreq += 1;

        return nodeUmap[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0)
            return;

        if (this->get(key) != -1) {
            nodeUmap[key].first = value;
            return;
        }

        if (size >= capacity) {
            nodeUmap.erase(dequeByFreq[minFreq].front());
            iterUmap.erase(dequeByFreq[minFreq].front());
            dequeByFreq[minFreq].pop_front();
            size -= 1;
        }

        nodeUmap[key] = {value, 1};
        dequeByFreq[1].push_back(key);
        iterUmap[key] = prev(dequeByFreq[1].end());
        minFreq = 1;
        size += 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */