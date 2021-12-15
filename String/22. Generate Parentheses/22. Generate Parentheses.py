'''
Number: 22
Topic: Generate Parentheses
Date: 2021/10/17
Rate: Medium
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Constraints:
    * 1 <= n <= 8
'''

# left <= n
# right <= n
# left >= right


class Solution:
    def __init__(self):
        self.results = list()

    def generateParenthesis(self, n: int) -> List[str]:

        def generate(result, leftCount, rightCount):
            if leftCount == 0 and rightCount == 0:
                self.results.append(result)

            if leftCount > 0:
                generate(result+"(", leftCount-1, rightCount+1)
            if rightCount > 0:
                generate(result+")", leftCount, rightCount-1)

        generate("", n, 0)
        return self.results
