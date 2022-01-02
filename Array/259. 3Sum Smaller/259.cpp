/*
<LeetCodePracticeC++>
    
- Name: 259. 3Sum Smaller
- Difficulty: Medium
- URL: https://leetcode.com/problems/3sum-smaller/
- Description: 
    Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
- Constraints:
    - n == nums.length
    - 0 <= n <= 3500
    - -100 <= nums[i] <= 100
    - -100 <= target <= 100
- Date: 12/29/2021

</LeetCodePracticeC++>
*/

/*
POA:
    nuns.sort()
    for idx, one in enum(nums):
        two, ptr = nums[one+1]
        three, ptr = nums.back()
        while (two < three):
            if (one+two+three < nums):
                result += (three - two + 1)
                two_ptr += 1
                three_ptr = nums.size()-1
            else if (one+two+three => nums):
                three_ptr -= 1
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    result += k - j;
                    j += 1;
                    k = n - 1;
                } else { 
                    // sum >= target
                    k -= 1;
                }
            }
        }
        return result;
    }
};

