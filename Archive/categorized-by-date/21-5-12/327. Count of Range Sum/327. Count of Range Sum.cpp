/*
Number: 327
Topic: Count of Range Sum
Date: 2021/5/12
Rate: Hard
https://leetcode.com/problems/count-of-range-sum/

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

Constraints:
* 1 <= nums.length <= 104
* -231 <= nums[i] <= 231 - 1
* -105 <= lower <= upper <= 105
* The answer is guaranteed to fit in a 32-bit integer.


tc: O(nlog(n))
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        // 因為 range sum 也就是兩個 prefix sum 的值互減 sum[a]-sum[b] = sum(nums[a:b])
        // 所以先製造一個 prefix sum 的 array
        vector<double> sum = {0};
        for (int i = 0; i < nums.size(); i++) {
        	sum.push_back(sum[i]+nums[i]);
        }
        mergeSortCount(sum, 0, sum.size()-1, count, lower, upper);

        return count;
    }

    // 邏輯和判斷在一個 array 裡面右邊有多少大於左邊 element 的值一樣，用 merge sum 可以得到 O(nlog(n))的結果
   	void mergeSortCount(vector<double>& sum, int start, int end, int& count, int lower, int upper) {
   		if (start >= end) return;

   		int mid = start + (end-start) / 2;
   		mergeSortCount(sum, start, mid, count, lower, upper);
   		mergeSortCount(sum, mid+1, end, count, lower, upper);
   		merge(sum, start, mid, end, count, lower, upper);
   	}

   	void merge(vector<double>& sum, int start, int mid, int end, int& count, int lower, int upper) {
   		
   		vector<double> temp;
   		int low_pos = mid+1, high_pos = mid+1;
   		int right = mid+1;
   		for (int left = start; left <= mid; left++) {
   			// 右邊那半的值減去左邊的值，至少要大於 lower bound
   			while ((low_pos <= end) && ((sum[low_pos]-sum[left]) < lower))
   				low_pos++;
   			// 右邊那半的值減去左邊的值，至少要大於 upper bound，這邊用大於小於是為了在 high_pos-low_pos 時有 +1 的效果
   			while ((high_pos <= end) && ((sum[high_pos]-sum[left]) <= upper))
   				high_pos++;
   			// sum(nums[left:x]) x in [mid+1, end] 符合 [lower, upper] 的數量，就是 high_pos-low_pos
   			count += (high_pos-low_pos);

   			// 一般的 merge sort
   			while ((right <= end) && (sum[right] < sum[left])) {
   				temp.push_back(sum[right++]);
   			}
   			temp.push_back(sum[left]);
   		}

   		while (right <= end) {
   			temp.push_back(sum[right++]);
   		}

   		// in-place copy
   		for (int i = 0; i < temp.size(); i++) {
   			sum[start+i] = temp[i];
   		}
   	}
};