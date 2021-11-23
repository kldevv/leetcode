/*
Number: 170
Topic: Two Sum III - Data structure design
Date: 2021/7/24
Rate: Easy
https://leetcode.com/problems/two-sum-iii-data-structure-design/

Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:
* TwoSum() Initializes the TwoSum object, with an empty array initially.
* void add(int number) Adds number to the data structure.
* boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.

Constraints:
* -105 <= number <= 105
* -231 <= value <= 231 - 1
* At most 5 * 104 calls will be made to add and find.
*/

class TwoSum {
private:
    unordered_map<int, int> umap;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        umap[number] += 1;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto p : umap) {
            int num = p.first;

            if (value == INT_MIN && num > 0)
                continue;
            
            int offset = value - num;

            if (num == offset && umap[num] > 1 || num != offset && umap.count(offset))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */