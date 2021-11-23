/*
Number: 365
Topic: Water and Jug Problem
Date: 2021/6/10
Rate: Medium
https://leetcode.com/problems/water-and-jug-problem/

* You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

* If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

* Fill any of the jugs with water.
* Empty any of the jugs.
* Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.


Constraints:
* 1 <= jug1Capacity, jug2Capacity, targetCapacity <= 106

*/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // 把 targetCapacity 想成 jug1 跟 jug2 的排列組合
        // xj1 + yj2 = tj;
        // tj 可以寫成 j1 和 j2 的 GCD，Bézout's identity

    	// the problem says that can only fill up those two jugs
        if (targetCapacity > jug1Capacity + jug2Capacity)
        	return false;
        if (targetCapacity == jug1Capacity || targetCapacity == jug2Capacity)
        	return true;

        return !targetCapacity%GCD(jug1Capacity, jug2Capacity);
    }

    int GCD(int n1, int n2) {
    	// Euclidean Algo
    	if (n2 == 0)
    		return n1;
    	return GCD(n2, n1%n2);
    }
};