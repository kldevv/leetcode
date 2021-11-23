/*
Number: 706
Topic: Design HashMap
Date: 2021/11/1
Rate: Easy
https://leetcode.com/problems/design-hashmap/

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:
    * MyHashMap() initializes the object with an empty map.
    * void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    * int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    * void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

Constraints:
    * 0 <= key, value <= 106
    * At most 104 calls will be made to put, get, and remove.
*/

class MyHashMap {
private:
    vector<vector<pair<int, int>>> mapToward;
    static const int SIZE = 2069;
public:
    MyHashMap() {
        this->mapToward = vector<vector<pair<int, int>>>(SIZE, vector<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int modKey = key % SIZE;
        bool found = false;
        for (int i = 0; i < mapToward[modKey].size(); i++) {
            if (mapToward[modKey][i].first == key) {
                found = true;
                mapToward[modKey][i] = make_pair(key, value);
            }
        }
        if (!found)
            mapToward[modKey].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int modKey = key % SIZE;
        for (pair<int, int> p : mapToward[modKey]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int modKey = key % SIZE;
        bool found = false;
        int idx = -1;
        for (int i = 0; i < mapToward[modKey].size(); i++) {
            if (mapToward[modKey][i].first == key) {
                found = true;
                idx = i;
            }
        }
        if (found)
            mapToward[modKey].erase(mapToward[modKey].begin()+idx);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
