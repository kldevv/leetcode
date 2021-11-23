'''
Number: 274
Topic: H-Index
Date: 2021/3/31
Rate: Medium

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

'''


# use hashmap to record count

# time complexity O(n)
# space complexity O(1)

# the possible solution will be at the range {0, ..., l + 1} where l be the length of the input array

class Solution:
    def hIndex(self, citations: [int]) -> int:
        base = 0
        for idx in range(len(citations)):
            if citations[idx] > len(citaions):
                citations[idx] = 0
                base += 1

        leng = len(citations) + 1
        citations.append(0)
        for idx in range(len(citations)):
            citations[citations[idx]%leng] += leng

        accu = 0
        for idx in range(leng-1, -1, -1):
            count = citations[idx] // leng
            if (count + base + accu) >= idx:
                return idx
            accu += count







