'''
Number: 380
Topic: Insert Delete GetRandom O(1)
Date: 2021/10/14
Rate: Medium
https://leetcode.com/problems/insert-delete-getrandom-o1/

Implement the RandomizedSet class:
    * RandomizedSet() Initializes the RandomizedSet object.
    * bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    * bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    * int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

Constraints:
    * board.length == 9
    * board[i].length == 9
    * board[i][j] is a digit 1-9 or '.'.
'''
from random import randint
class RandomizedSet:
    def __init__(self):
        self.nums = list()
        self.hashmap = dict()
        self.size = 0

    def insert(self, val: int) -> bool:
        if val in self.hashmap:
            return False

        self.nums.append(val)
        self.hashmap[val] = self.size
        self.size += 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hashmap:
            return False

        idx = self.hashmap[val]
        self.nums[idx], self.nums[-1] = self.nums[-1], self.nums[idx]
        self.hashmap[self.nums[idx]] = idx
        self.hashmap.pop(self.nums[-1], None)
        self.nums.pop()
        self.size -= 1
        return True

    def getRandom(self) -> int:
        idx = randint(0, len(self.nums)-1)
        return self.nums[idx]

# a = RandomizedSet()
# a.insert(1)
# a.remove(2)
# a.insert(2)
# a.getRandom()
# a.remove(1)
# a.insert(1)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()