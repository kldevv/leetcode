// 2021/12/29

#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> offset(60, 0);

        int result = 0;
        for (int num : time) {
            result += offset[(60 - num%60) % 60];
            offset[num%60] += 1;
        }

        return result;
    }
};