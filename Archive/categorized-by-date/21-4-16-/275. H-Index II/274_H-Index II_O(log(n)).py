'''
Number: 275
Topic: H-Index II
Date: 2021/4/2
Rate: Medium

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

FOLLOW UP: can you solve this problem in logarithmic time complexity?

'''

# binary search
# time complexity O(n)
# space complexity O(1)

class Solution:
    def hIndex(self, citations):
        length = len(citations)
        first = 0
        count = length
        
        while count > 0:
            half = count // 2
            mid = first + half

            if citations[mid] < length - mid:
                first = mid + 1
                count -= (half + 1)
            else:
                count = half
        
        return length - first

# [0,1,3,5,6]
# first = 0, leng = 5, count = 5
# half = 5 // 2 = 2
# mid = 0 + 2 = 2
# citations[mid] = 3

#  -> count = 2

# [0,1,3,5,6]
# first = 0, leng = 5, count = 2
# half = 2 // 2 = 1
# mid = 0 + 1 = 1
# citations[mid] = 1

# -> first = 1 + 1 = 2
# -> count = 2 - 1 - 1 = 0



