/*
Number: 220
Topic: Contains Duplicate III
Date: 2021/9/6
Rate: Medium
https://leetcode.com/problems/contains-duplicate-iii/

Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

Constraints:
    * 0 <= nums.length <= 2 * 104
    * -231 <= nums[i] <= 231 - 1
    * 0 <= k <= 104
    * 0 <= t <= 231 - 1
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0)
            return false;
        unordered_map<long, long> bucket;

        for (long i = 0; i < nums.size(); i++) {
            long placement = (t) ? nums[i] / t : nums[i];
            // cout << nums[i] << " " << placement << endl;
            vector<long> curBucket;
            if (bucket.count(placement))
                curBucket.push_back(bucket[placement]);
            if (bucket.count(placement-1))
                curBucket.push_back(bucket[placement-1]);
            if (bucket.count(placement+1))
                curBucket.push_back(bucket[placement+1]);

            for (long idx : curBucket) {
                if (abs((long)nums[idx] - (long)nums[i]) <= t && abs(i - idx) <= k)
                    return true;
            }
            bucket[placement] = i;
        }

        return false;
    }
};