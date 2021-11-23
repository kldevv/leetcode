'''
Number: 17
Topic: Letter Combinations of a Phone Number
Date: 2021/10/17
Rate: Medium
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Constraints:
    * 0 <= digits.length <= 4
    * digits[i] is a digit in the range ['2', '9'].
'''

class Solution:
    def __init__(self):
        self.letters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxzy",
        }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        results = [""]
        for digit in digits:
            new_results = list()
            for result in results:
                for letter in self.letters[digit]:
                    new_results.append(result + letter)
            results = new_results
        return results


