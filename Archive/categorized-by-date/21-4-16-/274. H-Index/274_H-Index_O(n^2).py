'''
Number: 274
Topic: H-Index
Date: 2021/3/31
Rate: Medium

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

'''


'''
Number: 274
Topic: H-Index
Date: 2021/3/31
Rate: Medium

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

'''


# brute force
# time complexity O(n^2)
# space complexity O(1)

class Solution:
    def hIndex(self, citations: [int]) -> int:
        max_ = 0
        for num in range(len(citations) + 1):
            if num > max_:
                count = 0
                for idx in range(len(citations)):
                    if citations[idx] >= num:
                        count += 1
                    if count >= num:
                        max_ = num
                        break
        return max_





