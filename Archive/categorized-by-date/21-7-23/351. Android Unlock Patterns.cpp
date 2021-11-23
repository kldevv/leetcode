/*
Number: 351
Topic: Android Unlock Patterns
Date: 2021/7/23
Rate: Medium
https://leetcode.com/problems/android-unlock-patterns/

Android devices have a special lock screen with a 3 x 3 grid of dots. Users can set an "unlock pattern" by connecting the dots in a specific sequence, forming a series of joined line segments where each segment's endpoints are two consecutive dots in the sequence. A sequence of k dots is a valid unlock pattern if both of the following are true:

* All the dots in the sequence are distinct.
* If the line segment connecting two consecutive dots in the sequence passes through the center of any other dot, the other dot must have previously appeared in the sequence. No jumps through the center non-selected dots are allowed.
    * For example, connecting dots 2 and 9 without dots 5 or 6 appearing beforehand is valid because the line from dot 2 to dot 9 does not pass through the center of either dot 5 or 6.
    * However, connecting dots 1 and 3 without dot 2 appearing beforehand is invalid because the line from dot 1 to dot 3 passes through the center of dot 2.

Here are some example valid and invalid unlock patterns:

* The 1st pattern [4,1,3,6] is invalid because the line connecting dots 1 and 3 pass through dot 2, but dot 2 did not previously appear in the sequence.
* The 2nd pattern [4,1,9,2] is invalid because the line connecting dots 1 and 9 pass through dot 5, but dot 5 did not previously appear in the sequence.
* The 3rd pattern [2,4,1,3,6] is valid because it follows the conditions. The line connecting dots 1 and 3 meets the condition because dot 2 previously appeared in the sequence.
* The 4th pattern [6,5,4,1,9,2] is valid because it follows the conditions. The line connecting dots 1 and 9 meets the condition because dot 5 previously appeared in the sequence.

Given two integers m and n, return the number of unique and valid unlock patterns of the Android grid lock screen that consist of at least m keys and at most n keys.

Two unlock patterns are considered unique if there is a dot in one sequence that is not in the other, or the order of the dots is different.

Constraints:
* 1 <= m, n <= 9
*/

class Solution {
public:
    const int DOTS = 9;

    int numberOfPatterns(int m, int n) {
        vector<vector<int>> passBy(DOTS+1, vector<int>(DOTS+1, 0));
        for (int curPos = 1; curPos <= DOTS; curPos++) {
            for (int nextPos = 1; nextPos <= DOTS; nextPos++) {
                int num = 0;
                if (curPos != nextPos && curPos + nextPos == 10) // pass the diagonal
                    num = 5;
                else if (curPos % 3 == 1 && nextPos - curPos == 2) // pass the horizontal neighbor
                    num = curPos + 1;
                else if (nextPos - curPos == 6) // pass the vertical neighbor
                    num = curPos + 3;
                if (num) {
                    passBy[curPos][nextPos] = num;
                    passBy[nextPos][curPos] = num;
                }
            }
        }

        vector<int> visited(DOTS+1, 0);
        int out = 0;
        for (int step = m; step <= n; step++) {
            out += numberOfPatterns(1, step, visited, passBy) * 4;
            out += numberOfPatterns(2, step, visited, passBy) * 4;
            out += numberOfPatterns(5, step, visited, passBy);
        }
        return out;
    }

    int numberOfPatterns(int curPos, int remainStep, vector<int>& visited, const vector<vector<int>>& passBy) {
        if (remainStep == 1)
            return 1;

        visited[curPos] = 1;

        int out = 0;
        for (int nextPos = 1; nextPos <= DOTS; nextPos++) {
            if (!visited[nextPos]) {
                int passByNum = passBy[curPos][nextPos];
                if (!passByNum || visited[passByNum])
                    out += numberOfPatterns(nextPos, remainStep-1, visited, passBy);
            }
        }

        visited[curPos] = 0;

        return out;
    }
};