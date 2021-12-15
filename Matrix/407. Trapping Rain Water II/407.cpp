/*
<LeetCodePracticeC++>
    
- Name: 407. Trapping Rain Water II
- Difficulty: Hard
- URL: https://leetcode.com/problems/trapping-rain-water-ii/
- Description: 
    
    Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

- Constraints:
    - m == heightMap.length
    - n == heightMap[i].length
    - 1 <= m, n <= 200
    - 0 <= heightMap[i][j] <= 2 * 104

- Date: 12/13/2021

</LeetCodePracticeC++>
*/
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {
        {1, 0}, 
        {-1, 0},
        {0, 1},
        {0, -1}
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        /*
        Check all boundary
        Move toward inside and update the heigh
        The calculate the minimum boundary neighbor first, as their minimum boundary is this boundary
        */
        if (heightMap.size() == 0 || heightMap[0].size() == 0)
            return 0;

        int n = heightMap.size();
        int m = heightMap[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> boundaries;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    visited[i][j] = 1;
                    boundaries.push({heightMap[i][j], i, j});
                }
            }
        }

        int boundaryHeight = INT_MIN;
        int water = 0;
        while (boundaries.size()) {
            vector<int> tuple = boundaries.top();
            boundaries.pop();

            boundaryHeight = max(boundaryHeight, tuple[0]);
            int i = tuple[1];
            int j = tuple[2];

            for (vector<int> dir : directions) {
                int ii = i + dir[0];
                int jj = j + dir[1];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m || visited[ii][jj])
                    continue;

                visited[ii][jj] = 1;
                water += max(boundaryHeight - heightMap[ii][jj], 0);
                boundaries.push({heightMap[ii][jj], ii, jj});
            }
        }
        return water;
    }
};
