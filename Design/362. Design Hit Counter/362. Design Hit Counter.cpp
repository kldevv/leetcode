/*
Number: 362
Topic: Design Hit Counter
Date: 2021/12/4
Rate: Medium
https://leetcode.com/problems/design-hit-counter/

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:
    * HitCounter() Initializes the object of the hit counter system.
    * void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
    * int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

Constraints:
    * 1 <= timestamp <= 2 * 109
    * All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
    * At most 300 calls will be made to hit and getHits.

Follow up: What if the number of hits per second could be huge? Does your design scale?
*/
#include <deque>
#include <vector>

class HitCounter {
   private:
    deque<vector<int>> _logger;
    int _counter;

    void clean(int timestamp) {
        while (_logger.size() && timestamp - _logger.front()[0] >= 300) {
            _counter -= _logger.front()[1];
            _logger.pop_front();
        }
    }

   public:
    HitCounter() {
        /*
        deque() = [[timestamp, num]]
        */
        _counter = 0;
    }

    void hit(int timestamp) {
        /*
        if (timestamp == deque.back()[0])
            deque.back()[0] += 1
            hitCount += 1
        else
            deque.emplace_back(timestamp, 1);
        while (timestamp - deque.front()[0] >= 300)
            hitCount -= deque.front()[1]
            deque.pop_front()
        */
        if (_logger.size() && timestamp == _logger.back()[0])
            _logger.back()[1] += 1;
        else
            _logger.push_back({timestamp, 1});
        _counter += 1;
        clean(timestamp);
    }

    int getHits(int timestamp) {
        /*
        return hitCount;
        */
        clean(timestamp);
        return _counter;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */