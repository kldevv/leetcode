/*
Number: 158
Topic: Read N Characters Given Read4 II - Call multiple times
Date: 2021/7/19
Rate: Hard
https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

Given a file and assume that you can only read the file using a given method read4, implement a method read to read n characters. Your method read may be called multiple times.

Method read4:
* The API read4 reads four consecutive characters from file, then writes those characters into the buffer array buf4.
* The return value is the number of actual characters read.
* Note that read4() has its own file pointer, much like FILE *fp in C.

Method read:
* By using the read4 method, implement the method read that reads n characters from file and store it in the buffer array buf. Consider that you cannot manipulate file directly.
* The return value is the number of actual characters read.

Note:
* Consider that you cannot manipulate the file directly. The file is only accessible for read4 but not for read.
* The read function may be called multiple times.
* Please remember to RESET your class variables declared in Solution, as static/class variables are persisted across multiple test cases. Please see here for more details.
* You may assume the destination buffer array, buf, is guaranteed to have enough space for storing n characters.
* It is guaranteed that in a given test case the same buffer buf is called by read.

Constraints:
* 1 <= file.length <= 500
* file consist of English letters and digits.
* 1 <= queries.length <= 10
* 1 <= queries[i] <= 500

*/

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char buf4[4];
    int buf4Idx = 0;
    int buf4Count = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int bufIdx = 0;
        while (bufIdx < n) {
            // 當還沒有寫入 n 個 character 而且，buf4 裡還有未寫入 buf 的東西時，就先把 buf4 的東西寫入 buf 中
            while (bufIdx < n && buf4Idx < buf4Count) {
                buf[bufIdx++] = buf4[buf4Idx++];
            }
            // 當還沒有寫入 n 個 character 時，呼叫 read4，把 buf4 的東西更新，並且重置 buf4Idx，如果 file 中已經沒有東西了，就可以直接回傳 bufIdx（總共寫了多少東西）。
            if (bufIdx < n) {
                buf4Count = read4(buf4);
                buf4Idx = 0;
                if (!buf4Count)
                    return bufIdx;
            }
        }
        return bufIdx;
    }
};