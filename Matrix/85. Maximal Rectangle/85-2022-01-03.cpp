// 2022/01/03
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> nums;
        for (int j = 0; j < m; j++) {
            nums.push_back(matrix[0][j]-'0');
        }

        int maxArea = maximalRectangle(nums);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums[j] = (matrix[i][j] == '0') ? 0 : nums[j] + (matrix[i][j]-'0');
            }
            maxArea = max(maxArea, maximalRectangle(nums));
        }
        return maxArea;
    }

    int maximalRectangle(vector<int>& nums) {
        stack<int> cand;
        nums.push_back(-1);
        cand.push(-1);

        int maxArea = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (cand.top() != -1 && nums[cand.top()] > nums[i]) {
                int height = nums[cand.top()];
                cand.pop();
                int width = (i - cand.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            cand.push(i);
        }
        return maxArea;
    }
};