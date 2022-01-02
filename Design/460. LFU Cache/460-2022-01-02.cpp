// 2022/01/02
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
private:
int _capacity;
int _minfreq;
// key : (val, freq, *linkedListNode)
unordered_map<int, tuple<int, int, list<int>::iterator>> _cache;
// freq : linkedList
// new => old
unordered_map<int, list<int>> _freq;

public:
    LFUCache(int capacity) {
        _capacity = capacity;
        _minfreq = 1;
    }
    
    int get(int key) {
        if (_cache.count(key) == 0) {
            return -1;
        }
        auto [val, freq, iter] = _cache[key];
        _freq[freq].erase(iter);
        _freq[freq+1].push_front(key);
        _cache[key] = make_tuple(val, freq+1, _freq[freq+1].begin());

        if (_freq[_minfreq].empty()) {
            _minfreq += 1;
        }
        return val;
    }
    
    void put(int key, int value) {
        // cout << key << ":" << value << endl;
        // cout << "size = " << _cache.size() << endl;
        if (_capacity == 0)
            return;
        if (_cache.count(key)) {
            get(key);
            auto [val, freq, iter] = _cache[key];
            _cache[key] = make_tuple(value, freq, _freq[freq].begin());
        } else {
            if (_cache.size() == _capacity) {
                // eject
                int eject = _freq[_minfreq].back();
                // cout << "eject = " << eject << endl;
                _freq[_minfreq].pop_back();
                _cache.erase(eject);
            }
            _freq[1].push_front(key);
            _cache[key] = make_tuple(value, 1, _freq[1].begin());
            _minfreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */