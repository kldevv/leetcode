'''
Number: 134
Topic: Gas Station
Date: 2021/3/25
Rate: Medium

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

'''

# time complexity O(n^2)
# not good enough

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # the idea is to brute force all the starting point to see if there is a solution or return -1
        for idx in range(len(gas)):
            tank = 0
            count = 0
            for idx_2 in range(idx, len(gas) + idx):
                if idx_2 >= len(gas):
                    idx_2 -= len(gas)
                tank += gas[idx_2]
                tank -= cost[idx_2]
                count += 1
                if tank < 0:
                    break
                if count == len(gas):
                    return idx
        return -1
                



