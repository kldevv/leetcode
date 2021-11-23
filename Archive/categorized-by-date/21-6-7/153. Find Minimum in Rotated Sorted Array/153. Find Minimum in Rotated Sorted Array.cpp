/*
Number: 153
Topic: Find Minimum in Rotated Sorted Array
Date: 2021/6/7
Rate: Medium

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Constraints:
* n == nums.length
* 1 <= n <= 5000
* -5000 <= nums[i] <= 5000
* All the integers of nums are unique.
* nums is sorted and rotated between 1 and n times.

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // binary search
        int i = 0, j = nums.size()-1, mid = 0;
        while (i < j) {
            mid = i + (j-i)/2;
            // 如果往右邊看不是遞增，就代表起始點在右邊
            if (nums[mid] >= nums[j])
                i = mid + 1;
            // 如果是遞增，就代表起始點在左邊
            else
                j = mid;
        }
        return nums[i];
    }
};