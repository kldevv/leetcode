// 2022/01/03

#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
private:
    vector<int> _vals;
    // (val, pos)
    unordered_map<int, int> _pos;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (_pos.count(val))
            return false;

        _vals.push_back(val);
        _pos[val] = _vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (_pos.count(val) == 0)
            return false;
        _pos[_vals.back()] = _pos[val];
        _vals[_pos[val]] = _vals.back();

        _vals.pop_back();
        _pos.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % _vals.size();
        return _vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */