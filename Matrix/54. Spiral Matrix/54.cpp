/*
<LeetCodePracticeC++>
    
- Name: 54. Spiral Matrix
- Difficulty: Medium
- URL: https://leetcode.com/problems/spiral-matrix/
- Description: 

    Given an m x n matrix, return all elements of the matrix in spiral order.
    
- Constraints:
    - m == matrix.length
    - n == matrix[i].length
    - 1 <= m, n <= 10
    - -100 <= matrix[i][j] <= 100

- Date: 12/15/2021

</LeetCodePracticeC++>
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        i=0,j=0 ..... i=0,j=m -> j += 1
        i=0,j=n ..... i=n,j=m -> i += 1
        i=n,j=m ..... i=n,j=0 -> j -= 1
        i=n,j=0 ..... i=0,j=0 -> i -= 1

        deltaI = 0, deltaJ = 1
        deltaI = 1, deltaJ = 0
        deltaI = 0, deltaJ = -1
        deltaI = -1, deltaJ = 0
        */

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> results;

        int i = 0;
        int j = 0;
        int deltaI = 0;
        int deltaJ = 1;
        while (results.size() < m * n) {
            results.push_back(matrix[i][j]);
            matrix[i][j] = -101;
            if (matrix[(i+deltaI+n) % n][(j+deltaJ+m) % m] == -101) {
                swap(deltaI, deltaJ);
                deltaJ *= -1;
            }
            i = (i+deltaI+n) % n;
            j = (j+deltaJ+m) % m;
        }
        return results;
    }
};