/*
Number: 900
Topic: RLE Iterator
Date: 2021/8/20
Rate: Medium
https://leetcode.com/problems/rle-iterator/

We can use run-length encoding (i.e., RLE) to encode a sequence of integers. In a run-length encoded array of even length encoding (0-indexed), for all even i, encoding[i] tells us the number of times that the non-negative integer value encoding[i + 1] is repeated in the sequence.

* For example, the sequence arr = [8,8,8,5,5] can be encoded to be encoding = [3,8,2,5]. encoding = [3,8,0,9,2,5] and encoding = [2,8,1,8,2,5] are also valid RLE of arr.

Given a run-length encoded array, design an iterator that iterates through it.

Implement the RLEIterator class:
* RLEIterator(int[] encoded) Initializes the object with the encoded array encoded.
* int next(int n) Exhausts the next n elements and returns the last element exhausted in this way. If there is no element left to exhaust, return -1 instead.

Constraints:
* 2 <= encoding.length <= 1000
* encoding.length is even.
* 0 <= encoding[i] <= 109
* 1 <= n <= 109
* At most 1000 calls will be made to next.
*/

class RLEIterator {
private:
    vector<int> encoding;
    int ptr;
    int offset;
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
        this->ptr = 0;
        this->offset = 0;
    }
    
    int next(int n) {
        offset += n;
        while (ptr < encoding.size() && offset > encoding[ptr]) {
            offset -= encoding[ptr];
            ptr += 2;
        }
        if (ptr >= encoding.size())
            return -1;
        return encoding[ptr+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */