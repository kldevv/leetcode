'''
Number: 692
Topic: Top K Frequent Words
Date: 2021/9/1
Rate: Medium
https://leetcode.com/problems/top-k-frequent-words/

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Constraints:
* 1 <= words.length <= 500
* 1 <= words[i] <= 10
* words[i] consists of lowercase English letters.
* k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
'''
from queue import PriorityQueue
class Element:
    def __init__(self, word, count):
        self.word = word
        self.count = count

    def __lt__(self, other) -> bool:
        # 先放 reverse lexicographical order, 因為最後要 reverse
        if self.count == other.count:
            return self.word > other.word
        return self.count < other.count

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        countWord = dict()
        # O(n)
        for word in words:
            countWord[word] = countWord.get(word, 0) + 1

        pq = PriorityQueue()
        # O(nlogk)
        for word, count in countWord.items():
            pq.put(Element(word, count))
            while pq.qsize() > k:
                pq.get()
        # O(nlogk)
        result = [pq.get().word for _ in range(k) if not pq.empty()]
        # O(k)
        return result[::-1]
