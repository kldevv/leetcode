/*
Number: 157
Topic: Read N Characters Given Read4
Date: 2021/7/19
Rate: Easy
https://leetcode.com/problems/read-n-characters-given-read4/

Given a file and assume that you can only read the file using a given method read4, implement a method to read n characters.

Method read4:
* The API read4 reads four consecutive characters from file, then writes those characters into the buffer array buf4.
* The return value is the number of actual characters read.
* Note that read4() has its own file pointer, much like FILE *fp in C.

Method read:
* By using the read4 method, implement the method read that reads n characters from file and store it in the buffer array buf. Consider that you cannot manipulate file directly.
* The return value is the number of actual characters read.

Note:
* Consider that you cannot manipulate the file directly. The file is only accessible for read4 but not for read.
* The read function will only be called once for each test case.
* You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.

Constraints:
* 1 <= file.length <= 500
* file consist of English letters and digits.
* 1 <= n <= 1000

*/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while (count < n) {
            int increment = read4(buf+count);
            count += increment;
            if (increment < 4)
                break;
        }

        return min(count, n);
    }
};