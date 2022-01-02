// 2021/12/29
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);

        for (auto update : updates) {
            int start = update[0];
            result[start] += update[2];

            if (update[1] + 1 < length) {
                int end = update[1] + 1;
                result[end] -= update[2];
            }
        }

        for (int i = 1; i < length; i++) {
            result[i] += result[i-1];
        }

        return result;
    }
};