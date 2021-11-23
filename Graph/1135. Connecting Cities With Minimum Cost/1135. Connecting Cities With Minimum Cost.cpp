/*
Number: 1135
Topic: Connecting Cities With Minimum Cost
Date: 2021/9/28
Rate: Medium
https://leetcode.com/problems/connecting-cities-with-minimum-cost/

There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.

Constraints:
    * 1 <= n <= 104
    * 1 <= connections.length <= 104
    * connections[i].length == 3
    * 1 <= xi, yi <= n
    * xi != yi
    * 0 <= costi <= 105
*/

class Solution {
private:
    class DisjointSet {
    private:
        vector<int> parent;
        vector<int> weight;
    public:
        DisjointSet(int n) {
            this->weight = vector<int>(n, 1);
            this->parent = vector<int>(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int A) {
            // path compression
            if (parent[A] != A)
                parent[A] = find(parent[A]);
            return parent[A];
        }

        void unionSet(int A, int B) {
            int rootA = find(A);
            int rootB = find(B);

            // weighted union
            if (weight[rootA] >= weight[rootB]) {
                weight[rootA] += weight[rootB];
                parent[rootB] = rootA;
            }
            else {
                weight[rootB] += weight[rootA];
                parent[rootA] = rootB;
            }
        }

        bool notSameSet(int A, int B) {
            return find(A) != find(B);
        }
    };
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        DisjointSet* unionFind = new DisjointSet(n+1);

        sort(connections.begin(), connections.end(), [](vector<int>& A, vector<int>& B){
            return A[2] <= B[2];
        });

        int result = 0;
        int totalSet = n;
        for (vector<int>& connection : connections) {
            if (unionFind->notSameSet(connection[0], connection[1])) {
                unionFind->unionSet(connection[0], connection[1]);
                result += connection[2];
                totalSet -= 1;
            }
        }
        return (totalSet == 1) ? result : -1;
    }
};


