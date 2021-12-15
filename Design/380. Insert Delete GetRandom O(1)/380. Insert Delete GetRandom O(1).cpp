/*
Number: 380
Topic: Insert Delete GetRandom O(1)
Date: 2021/12/7
Rate: Medium
https://leetcode.com/problems/insert-delete-getrandom-o1/

Implement the RandomizedSet class:
    * RandomizedSet() Initializes the RandomizedSet object.
    * bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    * bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    * int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

Constraints:
    * -231 <= val <= 231 - 1
    * At most 2 * 105 calls will be made to insert, remove, and getRandom.
    * There will be at least one element in the data structure when getRandom is called.
*/

#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
   private:
    vector<int> vals;
    unordered_map<int, int> getIdx;

   public:
    RandomizedSet() {
    }

    bool insert(int val) {
        // if val is present
        if (getIdx.count(val))
            return false;
        // else
        vals.push_back(val);
        getIdx[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val) {
        // swap the chosen element with the back
        // get chosen index in constant time
        // pop back
        if (getIdx.count(val) == 0)
            return false;
        swap(vals[getIdx[val]], vals[vals.size() - 1]);

        // update getIdx
        getIdx[vals[getIdx[val]]] = getIdx[val];
        getIdx.erase(val);
        vals.pop_back();
        return true;
    }

    int getRandom() {
        // get random index and random access in constant time
        // rand() % n
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
