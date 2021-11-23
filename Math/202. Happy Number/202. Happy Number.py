'''
Number: 202
Topic: Happy Number
Date: 2021/10/14
Rate: Easy
https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
    * Starting with any positive integer, replace the number by the sum of the squares of its digits.
    * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    * Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Constraints:
    * 1 <= n <= 231 - 1
'''
class Solution:
    def isHappy(self, n: int) -> bool:
        def happy(n: int) -> int:
            result = 0
            while n:
                digit = n % 10
                result += digit * digit
                n //= 10
            return result

        slow = happy(n)
        fast = happy(happy(n))
        if slow == 1 or fast == 1:
            return True
        while slow != fast:
            slow = happy(slow)
            fast = happy(happy(fast))
            if slow == 1 or fast == 1:
                return True
        return False

# a = Solution()
# print(a.isHappy(2))