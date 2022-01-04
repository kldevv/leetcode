#include <deque>

class HitCounter {
    int _hit;
    // (timestamp, hit)
    deque<pair<int, int>> _logger;
public:
    HitCounter() {
        _hit = 0;
    }
    void clean(int timestamp) {
        while (_logger.size() && (timestamp - _logger.front().first >= 300)) {
            _hit -= _logger.front().second;
            _logger.pop_front();
        }
    }
    
    void hit(int timestamp) {
        clean(timestamp);
        if (_logger.empty() || timestamp != _logger.back().first) {
            _logger.push_back(make_pair(timestamp, 1));
        } else {
            _logger.back().second += 1;
        }
        _hit += 1;
    }
    
    int getHits(int timestamp) {
        clean(timestamp);
        return _hit;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */