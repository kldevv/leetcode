/*
<LeetCodePracticeC++>
    
- Name: 349. Intersection of Two Arrays
- Difficulty: Easy
- URL: https://leetcode.com/problems/intersection-of-two-arrays/
- Description:
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

- Constraints:
    - 1 <= nums1.length, nums2.length <= 1000
    - 0 <= nums1[i], nums2[i] <= 1000

- Date: 12/12/2021

</LeetCodePracticeC++>
*/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*
        s1 = Set(nums1);
        // Set ofSmallerSize(nums1, nums2);
        
        Init result
        for num in nums2:
            if num in s1:
               results.Add(num);
               s1.Remove(num);

        return results
        */
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        unordered_set<int> setNums1(nums1.begin(), nums1.end());
        vector<int> results;
        for (int num : nums2) {
            if (setNums1.find(num) != setNums1.end()) {
                results.push_back(num);
                setNums1.erase(num);
            }
        }
        return results;
    }
};


