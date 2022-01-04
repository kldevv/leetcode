#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(1, 1);
    unordered_map<int, int> power;
    power[2] = 0;
    power[3] = 0;
    power[5] = 0;

    while ((int)ugly.size() < n) {
        int next = INT_MAX;
        for (auto [pow, ptr] : power) {
            next = min(next, ugly[ptr] * pow);
        }
        for (auto& [pow, ptr] : power) {
            if (ugly[ptr] * pow == next) {
                ptr += 1;
            }
        }
        ugly.push_back(next);
    }
    return ugly.back();
}
