// 2021/12/30

/*
max * max_1 * max_2
or max * min_1 * min_2
*/

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> smallest;
        priority_queue<int, vector<int>, greater<int>> biggest;
        for (int num : nums) {
            biggest.push(num);
            smallest.push(num);

            if (biggest.size() > 3) {
                biggest.pop();
            }
            if (smallest.size() > 2) {
                smallest.pop();
            }
        }
        int b2 = biggest.top();
        biggest.pop();
        int b1 = biggest.top();
        biggest.pop();
        int n = biggest.top();
        biggest.pop();

        int s1 = smallest.top();
        smallest.pop();
        int s2 = smallest.top();
        smallest.pop();

        return max(n * b1 * b2, n * s1 * s2);
    }
};