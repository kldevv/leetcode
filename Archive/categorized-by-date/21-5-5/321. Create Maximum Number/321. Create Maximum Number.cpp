/*
Number: 321
Topic: Create Maximum Number
Date: 2021/5/5
Rate: Hard

You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the k digits representing the answer.
*/


/*
grade / pass
tc / O(n) where n = number of intervals
sc / O(1) if in-place
*/

class Solution {
public:
    vector<int> maxNumber(vector<int> nums, int k){
        vector<int> out;
        int drop = nums.size() - k;
        for (int num : nums){
            while(out.size() && drop && out.back() < num){
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2){
        vector<int> out;
        while (nums1.size() + nums2.size()){
            vector<int>& bigHead = nums1 > nums2 ? nums1 : nums2;
            out.push_back(bigHead[0]);
            bigHead.erase(bigHead.begin());
        }
        return out;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i = max((k - size2), 0); i <= min(size1, k); i++){
            best = max(best, maxNumber(
                maxNumber(nums1, i),
                maxNumber(nums2, k-i)));
        }
        return best;
    }

};

