/*
Number: 380
Topic: Insert Delete GetRandom O(1)
Date: 2021/7/5
Rate: Medium
https://leetcode.com/problems/insert-delete-getrandom-o1/

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

Constraints:
* -231 <= val <= 231 - 1
* At most 2 * 105 calls will be made to insert, remove, and getRandom.
* There will be at least one element in the data structure when getRandom is called.

*/


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.count(val) && umap[val] != -1)
            return false;

        nums.push_back(val);
        umap[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!umap.count(val) || umap[val] == -1)
            return false;

        swap(nums[nums.size()-1], nums[umap[val]]);
        nums.pop_back();
        umap[nums[umap[val]]] = umap[val];
        umap[val] = -1;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
private:
    vector<int> nums;
    unordered_map<int, int> umap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */