// 2021/12/29
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;
        for (int i = 0; i < nums.size(); i++) {
            while (window.size() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if (window.size() && (i - window.front() + 1) > k) {
                window.pop_front();
            }

            if (i + 1 >= k) {
                result.push_back(nums[window.front()]);
            }
        }
        return result;
    }
};