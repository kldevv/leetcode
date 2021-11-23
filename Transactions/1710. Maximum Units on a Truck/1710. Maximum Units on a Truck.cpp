/*
Number: 1710
Topic: Maximum Units on a Truck
Date: 2021/9/15
Rate: Easy
https://leetcode.com/problems/maximum-units-on-a-truck/

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

    * numberOfBoxesi is the number of boxes of type i.
    * numberOfUnitsPerBoxi is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Constraints:
    * 1 <= boxTypes.length <= 1000
    * 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
    * 1 <= truckSize <= 106
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& A, vector<int>& B) { return A[1] > B[1];});

        int result = 0;
        auto box = boxTypes.begin();
        while (box != boxTypes.end() && truckSize) {
            result += (min((*box)[0], truckSize) * (*box)[1]);
            truckSize -= min((*box)[0], truckSize);
            box++;
        }
        return result;
    }
};