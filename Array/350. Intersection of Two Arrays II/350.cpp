/*
<LeetCodePracticeC++>
    
- Name: 350. Intersection of Two Arrays II
- Difficulty: Easy
- URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/
- Description: 
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

- Constraints:
    - 1 <= nums1.length, nums2.length <= 1000
    - 0 <= nums1[i], nums2[i] <= 1000

- Follow up?:
    - 1. What if the given array is already sorted? How would you optimize your algorithm?
        - Two pointers, O(1) space
    - 2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
        - Use the solution below
    - 3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
        - Use the solution below
    - 4. What if memory is not enough to load both nums1 and nums2?
        - Split the numeric range and solve a certain range one by one.

- Date: 

</LeetCodePracticeC++>
*/

#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        counter = Count(nums1);
        // Count OfSmallerSize(nums1, nums2)
        
        for num in nums2 (nums1):
            if num in counter && counter[num] > 0:
                results.Add(num);
                counter[num] -= 1;
        return results;
        */

        // Complexity:
        // T(n, m) = O(n + m)
        // S(n, m) = O(min(n, m))
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> counter;

        // given nums1.size() < nums2.size()
        for (int num : nums1) {
            counter[num] += 1;
        }

        vector<int> results;
        for (int num : nums2) {
            if (counter.find(num) != counter.end() && counter[num] > 0) {
                results.push_back(num);
                counter[num] -= 1;
            }
        }
        return results;
    }
};

