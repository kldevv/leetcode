/*
Number: 277
Topic: Find the Celebrity
Date: 2021/7/16
Rate: Medium
https://leetcode.com/problems/find-the-celebrity/

Suppose you are at a party with n people (labeled from 0 to n - 1), and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her, but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

Constraints:
* n == graph.length
* n == graph[i].length
* 2 <= n <= 100
* graph[i][j] is 0 or 1.
* graph[i][i] == 1
 
Follow up: If the maximum number of allowed calls to the API knows is 3 * n, could you find a solution without exceeding the maximum number of calls?
*/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            // 如果 candidate 認識某一個人，就代表他不是 candidate
            // 如果 candidate 不認識 ｉ，那 i 就不可能是 candidate
            if (knows(candidate, i)) 
                candidate = i;
        }

        for (int i = 0; i < n; i++) {
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate)))
                return -1;
        }
        return candidate;
    }
};

