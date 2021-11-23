'''
Number: 771
Topic: Jewels and Stones
Date: 2021/10/14
Rate: Easy
https://leetcode.com/problems/jewels-and-stones/

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

Constraints:
    * 1 <= jewels.length, stones.length <= 50
    * jewels and stones consist of only English letters.
    * All the characters of jewels are unique.
'''

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        set_ = set()
        for c in jewels:
            set_.add(c)

        result = 0
        for c in stones:
            if c in set_:
                result += 1
        return result

# a = Solution()
# a.numJewelsInStones('aA', 'aa')