/*
Number: 281
Topic: Zigzag Iterator
Date: 2021/7/24
Rate: Medium
https://leetcode.com/problems/zigzag-iterator/

Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:
* ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
* boolean hasNext() returns true if the iterator still has elements, and false otherwise.
* int next() returns the current element of the iterator and moves the iterator to the next element.

Constraints:
* 0 <= v1.length, v2.length <= 1000
* 1 <= v1.length + v2.length <= 2000
* -231 <= v1[i], v2[i] <= 231 - 1

Follow up: What if you are given k vectors? How well can your code be extended to such cases?

Clarification for the follow-up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic"
*/

class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty())
            q.push({v1.begin(), v1.end()});
        if (!v2.empty())
            q.push({v2.begin(), v2.end()});
    }

    int next() {
        vector<int>::iterator iter = q.front().first;
        vector<int>::iterator end = q.front().second;
        q.pop();

        if (iter + 1 != end)
            q.push({iter+1, end});

        return *iter;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */