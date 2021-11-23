/*
Number: 367
Topic: Valid Perfect Square
Date: 2021/6/5
Rate: Easy

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

Constraints:
* 1 <= num <= 2^31 - 1

*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1, j = num, m = 0;
        while (i <= j) {
            cout << m << endl;
            m = i + (j-i)/2;
            if (m == num/m)
                return true;
            else if (m < num/m)
                i = m+1;
            else
                j = m-1;
        }
        return false;
    }
};