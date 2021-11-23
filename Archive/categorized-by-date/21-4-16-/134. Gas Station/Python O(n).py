'''
Number: 134
Topic: Gas Station
Date: 2021/3/25
Rate: Medium

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

'''

# time complexity O(n)
# space complexity O(1)

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # create an diff array
        for idx in range(len(gas)):
            gas[idx] -= cost[idx]
        
        # if the total gas is greater than the total cost there must be a solution
        sum_ = 0
        for diff in gas:
            sum_ += diff
        if sum_ < 0:
            return -1

        # pick the weakest point and start from the next station to be sure that we use all the remaining gas to break that point
        smallest = gas[0]
        sma_idx = 0
        sum_ = 0
        for idx in range(len(gas)):
            sum_ += gas[idx]
            if sum_ <= smallest:
                smallest = sum_
                sma_idx = idx

        return (sma_idx + 1) % len(gas)

