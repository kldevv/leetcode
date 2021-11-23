'''
Number: 17
Topic: Letter Combinations of a Phone Number
Date: 2021/10/5
Rate: Medium
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Constraints:
    * 0 <= digits.length <= 4
    * digits[i] is a digit in the range ['2', '9'].
'''

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(digits: str, start: int, match: dict[str], result: str, results: List[str]) -> None:
            if start == len(digits):
                if digits:
                    results.append(result)
                return

            for c in match[digits[start]]:
                dfs(digits, start+1, match, result+c, results)

        match = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }

        results = []
        dfs(digits, 0, match, "", results)
        return results