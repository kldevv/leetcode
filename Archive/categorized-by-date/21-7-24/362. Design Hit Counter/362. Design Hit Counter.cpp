/*
Number: 362
Topic: Design Hit Counter
Date: 2021/7/24
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

class HitCounter {
    vector<pair<int, int>> track;
    int count;
private:
    int before300(int timestamp) {
        if (track.empty())
            return 0;

        int lowerBound = max(timestamp - 300, 0);
        int idx = 0;
        int count = 0;

        while (idx < track.size() && track[idx].first <= lowerBound) {
            count += track[idx++].second;
        }
        return count;
    }
public:
    /** Initialize your data structure here. */
    HitCounter() {
        this->count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        count += 1;
        if (track.empty() || timestamp != track.back().first)
            track.push_back({timestamp, 1});
        else
            track.back().second += 1;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int cutoff = before300(timestamp);

        return this->count - cutoff;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */