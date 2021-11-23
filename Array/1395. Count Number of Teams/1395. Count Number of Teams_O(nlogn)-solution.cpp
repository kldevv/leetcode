/*
Number: 1395
Topic: Count Number of Teams_O(nlogn)-solution
Date: 2021/11/1
Rate: Medium
https://leetcode.com/problems/count-number-of-teams/

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:
* Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
* A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Constraints:
    * n == rating.length
    * 3 <= n <= 1000
    * 1 <= rating[i] <= 105
    * All the integers in rating are unique.
*/
class FenwickTree {
private:
    vector<int> container;
    int size;
public:
    FenwickTree(int size) {
        container = vector<int>(size, 0);
        this->size = size;
    }

    void increPut(int idx) {
        while (idx < size) {
            container[idx] += 1;
            idx += (idx & -idx);
        }
    }

    void decreRemove(int idx) {
        while (idx < size) {
            container[idx] -= 1;
            idx += (idx & -idx);
        }
    }

    int getPrefixSum(int idx) {
        // inclusive
        int sum = 0;
        while (idx > 0) {
            sum += container[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    int getSuffixSum(int idx) {
        // inclusive
        return getPrefixSum((this->size)-1) - getPrefixSum(idx-1);
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maxElement = *max_element(rating.cbegin(), rating.cend());
        
        FenwickTree* leftTree = new FenwickTree(maxElement+1);
        FenwickTree* rightTree = new FenwickTree(maxElement+1);

        for (int num : rating) {
            rightTree->increPut(num);
        }

        int result = 0;
        for (int num : rating) {
            rightTree->decreRemove(num);
            int increTeams = leftTree->getPrefixSum(num-1) * rightTree->getSuffixSum(num+1);
            int decreTeams = leftTree->getSuffixSum(num+1) * rightTree->getPrefixSum(num-1);
            result += increTeams + decreTeams;
            leftTree->increPut(num);
        }
        return result;
    }
};