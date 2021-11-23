'''
Number: 135
Topic: Candy
Date: 2021/4/29
Rate: Hard

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
'''

class Solution:
    def candy(self, ratings: [int]) -> int:
        distribution = [1] * len(ratings)
        for idx in range(1, len(ratings)):
            if ratings[idx] > ratings[idx-1]:
                distribution[idx] = distribution[idx-1] + 1
        for re_idx in range(len(ratings)-2, -1, -1):
            if ratings[re_idx] > ratings[re_idx+1]:
                distribution[re_idx] = max(distribution[re_idx], distribution[re_idx+1]+1)
        return sum(distribution)

