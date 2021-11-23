/*
Number: 352
Topic: Data Stream as Disjoint Intervals
Date: 2021/7/28
Rate: Hard
https://leetcode.com/problems/data-stream-as-disjoint-intervals/

Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:
* SummaryRanges() Initializes the object with an empty stream.
* void addNum(int val) Adds the integer val to the stream.
* int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi].

Constraints:
* 0 <= val <= 104
* At most 3 * 104 calls will be made to addNum and getIntervals.
 
Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?
*/
class SummaryRanges {
private:
    struct comparator {
        bool operator()(const vector<int>& v1, const vector<int>& v2) const {
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] <= v2[1]);
        }
    };
    set<vector<int>> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        // blank
    }
    
    void addNum(int val) {
        int start = val;
        int end = val;
        vector<int> target = {start, end};
        set<vector<int>>::iterator notLess = lower_bound(intervals.begin(), intervals.end(), target, comparator());
        if (notLess != intervals.begin() && (*prev(notLess))[1]+1 >= start) {
            notLess--;
            start = min(start, (*notLess)[0]);
        }

        while (notLess != intervals.end() && end+1 >= (*notLess)[0]) {
            end = max(end, (*notLess)[1]);
            notLess = intervals.erase(notLess);
        }
        intervals.insert(notLess, {start, end});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> out;
        for (const vector<int>& i : intervals) {
            out.push_back(i);
        }
        return out;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */