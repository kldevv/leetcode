/*
Number: 1146
Topic: Snapshot Array
Date: 2021/9/8
Rate: Medium
https://leetcode.com/problems/snapshot-array/

Implement a SnapshotArray that supports the following interface:
    * SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
    * void set(index, val) sets the element at the given index to be equal to val.
    * int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
    * int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
Constraints:
    * 1 <= length <= 50000
    * At most 50000 calls will be made to set, snap, and get.
    * 0 <= index < length
    * 0 <= snap_id < (the total number of times we call snap())
    * 0 <= val <= 10^9
*/

class SnapshotArray {
private:
    unordered_map<string, int> permanent;
    unordered_map<int, int> thisPeriod;
    int snap_t;
public:
    SnapshotArray(int length) {
        this->snap_t = 0;
    }
    
    void set(int index, int val) {
        thisPeriod[index] = val;
    }
    
    int snap() {
        for (pair<int, int> p : this->thisPeriod) {
            string key = to_string(this->snap_t) + "#" + to_string(p.first);
            permanent[key] = p.second;
        }
        thisPeriod;
        snap_t += 1;
        return snap_t - 1;
    }
    
    int get(int index, int snap_id) {
        string key = to_string(snap_id) + "#" + to_string(index);

        return (permanent.count(key)) ? permanent[key] : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */