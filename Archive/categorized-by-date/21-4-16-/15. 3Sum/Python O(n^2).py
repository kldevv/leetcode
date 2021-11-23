'''
Number: 15 
Topic: 3Sum
Date: 2021/3/24
Rate: Medium

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
'''

# use the facts that -c = a + b, 3Sum problem reduce to 2Sum problem
# consider how to avoid duplicated result
class Solution:
    def threeSum(self, arr):
        # if the input has three or less elements, quickly check the result
        if len(arr) < 3:
            return []
        if len(arr) == 3:
            if (arr[0] + arr[1] + arr[2]) == 0:
                return [[arr[0], arr[1], arr[2]]]
            else:
                return []
        arr.sort()  # built-in time complexity n*log(n)
        result = []
        for x in range(len(arr) - 2):
            # skip if encounter the same value as the last one, or get the same triplets with the same given 1st element
            if (x > 0) and (arr[x] == arr[x-1]):
                continue
            target = arr[x] * -1
            start = x + 1
            end = len(arr) - 1

            # find the 2nd and 3rd elements given the 1st element
            while start < end:
                sum_2 = arr[start] + arr[end]
                if sum_2 == target:
                    result.append([arr[x], arr[start], arr[end]])
                    start += 1
                    # skip if encounter the same value as the last one, or get the same 3rd element with the same given 1st and 2nd element 
                    while (start < end) and (arr[start] == arr[start-1]):
                        start += 1
                # becasue the array is sorted, using increment and decrement method can keep the time complexity for 2Sum in O(n)
                elif sum_2 < target:
                    start += 1
                else:
                    end -= 1
        return result