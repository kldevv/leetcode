'''
Number: 49
Topic: Group Anagrams
Date: 2021/10/14
Rate: Medium
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:
    * 1 <= strs.length <= 104
    * 0 <= strs[i].length <= 100
    * strs[i] consists of lowercase English letters.
'''


class Solution:
    def groupAnagrams(self, strs):
        classifier = dict()
        for s in strs:
            counter = [0] * 26
            for c in s:
                counter[ord(c)-ord('a')] += 1
            mark = str(counter)

            if mark in classifier:
                classifier[mark].append(s)
            else:
                classifier[mark] = [s]

        results = list()
        for group in classifier.values():
            results.append(group)
        # print(results)
        return results

# a = Solution()
# a.groupAnagrams(["eat","tea","tan","ate","nat","bat"])
