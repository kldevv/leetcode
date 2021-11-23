/*
Number: 315
Topic: Count of Smaller Numbers After Self
Date: 2021/5/11
Rate: Hard
https://leetcode.com/problems/count-of-smaller-numbers-after-self/

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].


Constraints:

* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104

*/

class Solution {
private:
    // 存取原本位置和值，所以我們知道要把他的增值數字存在哪裡
    class valueIndex {
    public:
        int value;
        int idx;
        valueIndex(int value, int idx) : value{value}, idx{idx} {}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count;
        vector<valueIndex> pairs;
        // 這個用來存答案的
        for (int i = 0; i < nums.size(); i++) {
            count.push_back(0);
        }
        // 這個把 (value, idx) pair 放進去
        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back(valueIndex(nums[i], i));
        }
        mergeAndCount(pairs, 0, nums.size()-1, count);
        return count;
    }

    // 在做 merge sorting 的時候已經在比較右邊有幾個 element 比左邊小了
    vector<valueIndex> mergeAndCount(vector<valueIndex>& nums, int start, int end, vector<int>& count) {
        if (start == end) return {nums[start]};

        int mid = start + (end-start) / 2;
        vector<valueIndex> left = mergeAndCount(nums, start, mid, count);
        vector<valueIndex> right = mergeAndCount(nums, mid+1, end, count);

        vector<valueIndex> out;
        int left_pos = 0, right_pos = 0;
        int right_small_count = 0;

        while ((left_pos < left.size()) && (right_pos < right.size())) {
            if (left[left_pos].value > right[right_pos].value) {
                out.push_back(right[right_pos++]);
                // 右邊丟過去一個，左邊每一個紀錄的數值都要加一
                right_small_count++;             
            } else {
                out.push_back(left[left_pos]);
                count[left[left_pos++].idx] += right_small_count;
            }
        }
        while (left_pos < left.size()) {
            out.push_back(left[left_pos]);
            count[left[left_pos++].idx] += right_small_count; 
        }
        while (right_pos < right.size()) {
            out.push_back(right[right_pos++]);
        }

        return out;
    }
};





