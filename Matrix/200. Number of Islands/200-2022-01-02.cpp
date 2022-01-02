// 2022/01/02

class Solution {
private:
    int _m;
    int _n;
    vector<vector<int>> directions 
    {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        _n = grid.size();
        _m = grid[0].size();

        int result = 0;
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                if (grid[i][j] == '1') {
                    result += 1;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return result;
    }
    
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        if (isValid(i, j) && grid[i][j] == '1') {
            grid[i][j] = '0';
            for (auto dir : directions) {
                eraseIslands(grid, i+dir[0], j+dir[1]);
            }
        }
    }

    bool isValid(int i, int j) {
        return (i >= 0 && i < _n && j >= 0 && j < _m);
    }
};