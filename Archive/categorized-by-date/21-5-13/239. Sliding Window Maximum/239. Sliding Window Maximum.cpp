/*
Number: 239
Topic: Sliding Window Maximum
Date: 2021/5/13
Rate: Hard
https://leetcode.com/problems/sliding-window-maximum/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Constraints:
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* 1 <= k <= nums.length


ans: use queue
https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
ans: use partition
https://leetcode.com/problems/sliding-window-maximum/discuss/65881/O(n)-solution-in-Java-with-two-simple-pass-in-the-array
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 先做兩個 array， prefix max from the left and from the right
        // 而每次碰到第 k 個 就 reset
        vector<int> left_max = {nums[0]}, right_max = {nums[nums.size()-1]};
        left_max.reserve(nums.size()), right_max.reserve(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            left_max[i] = (i%k == 0) ? nums[i] : max(left_max[i-1], nums[i]);

            int j = nums.size()-1-i;
            right_max[j] = (j%k == 0) ? nums[j] : max(right_max[j+1], nums[j]);
        }

        // s1   s2
        // 4 2 | 1 4
        // sliding window 其實就是 [max(s1[:]), max(s1[1:], s2[:1]), s2[:]]
        vector<int> out;
        for (int i = 0; i+k <= nums.size(); i++) {
            // 所以每次只要比較 section bar (|) 左邊的最大值和右邊的最大值就好（兩邊的數量加起來剛好等於一個 windows 的長度）
            out.push_back(max(right_max[i], left_max[i+k-1]));
        }
        return out;
    }
};