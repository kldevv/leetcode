'''
Number: 472
Topic: Concatenated Words
Date: 2021/10/3
Rate: Hard
https://leetcode.com/problems/concatenated-words/

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Constraints:
    * 1 <= words.length <= 104
    * 0 <= words[i].length <= 1000
    * words[i] consists of only lowercase English letters.
    * 0 <= sum(words[i].length) <= 105
'''

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        valid_words = set(words)
        dp = dict()
        def isValid(word, valid_words, dp):
            if word in dp:
                return dp[word]

            dp[word] = False
            for idx in range(1, len(word)):
                prefix = word[:idx]
                suffix = word[idx:]

                if prefix in valid_words and suffix in valid_words:
                    dp[word] = True
                    break
                if prefix in valid_words and isValid(suffix, valid_words, dp):
                    dp[word] = True
                    break
            return dp[word]

        return [word for word in words if isValid(word, valid_words, dp)]



