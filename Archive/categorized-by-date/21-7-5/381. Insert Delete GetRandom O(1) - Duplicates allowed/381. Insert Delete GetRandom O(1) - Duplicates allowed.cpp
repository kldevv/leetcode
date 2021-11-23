/*
Number: 381
Topic: Insert Delete GetRandom O(1) - Duplicates allowed
Date: 2021/7/5
Rate: Hard
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called). The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works in average O(1) time complexity.

Constraints:
* -231 <= val <= 231 - 1
* At most 2 * 105  calls will be made to insert, remove, and getRandom.
* There will be at least one element in the data structure when getRandom is called.

*/


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        umap[val].insert(nums.size()-1);

        return umap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (umap[val].empty())
            return false;

        int n = nums.size();
        int idx = (nums[n-1] == val) ? n-1 : *umap[val].begin();
        if (idx != n-1) {
            umap[nums[n-1]].erase(n-1);
            umap[nums[n-1]].insert(idx);

            swap(nums[n-1], nums[idx]);
        } 
        umap[val].erase(idx);
        nums.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> umap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */