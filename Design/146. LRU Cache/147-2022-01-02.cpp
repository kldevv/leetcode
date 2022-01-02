// 2022/01/02
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int _capacity;
    // key : (val, *linkedlistNode)
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    // key
    // new => old
    list<int> _rec;


public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_cache.count(key) == 0)
            return -1;
        auto [val, iter] = _cache[key];
        _rec.erase(iter);
        _rec.push_front(key);
        _cache[key] = make_pair(val, _rec.begin());
        return val;
    }
    
    void put(int key, int value) {
        if (_capacity == 0)
            return;
        
        if (_cache.count(key)) {
            auto [val, iter] = _cache[key];
            _rec.erase(iter);
        } else {
            if (_cache.size() == _capacity) {
                _cache.erase(_rec.back());
                _rec.pop_back();
            }
        }    
        _rec.push_front(key);
        _cache[key] = make_pair(value, _rec.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */