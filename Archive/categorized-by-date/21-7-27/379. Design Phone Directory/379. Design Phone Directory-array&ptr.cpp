/*
Number: 378
Topic: Design Phone Directory
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/design-phone-directory/

Design a phone directory that initially has maxNumbers empty slots that can store numbers. The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:
* PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
* int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
* bool check(int number) Returns true if the slot number is available and false otherwise.
* void release(int number) Recycles or releases the slot number.

Constraints:
* 1 <= maxNumbers <= 104
* 0 <= number < maxNumbers
* At most 2 * 10^4 calls will be made to get, check, and release.
*/

class PhoneDirectory {
private:
    int curNum;
    vector<int> next;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->next = vector<int>(maxNumbers, 1);
        for (int i = 1; i < maxNumbers; i++) {
            this->next[i] = this->next[i-1] + 1;
        }
        this->curNum = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int val = -1;
        if (curNum < next.size()) {
            val = curNum;
            curNum = next[curNum];
            next[val] = -1;
        }
        return val;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return next[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (next[number] == -1) {
            next[number] = curNum;
            curNum = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */