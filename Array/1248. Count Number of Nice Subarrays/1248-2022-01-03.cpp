// 2022-01-03


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
    int atMostK(vector<int>& nums, int k) {
        int i = 0;
        int result = 0;
        for (int j = 0; j < nums.size(); j++) {
            k -= (nums[j] % 2);
            while (i <= j && k < 0) {
                k += (nums[i++] % 2);
            }
            result += (j - i + 1);
        }
        return result;
    }
};