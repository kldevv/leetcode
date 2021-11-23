/*
Number: 388
Topic: Longest Absolute File Path
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/longest-absolute-file-path/

Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:

Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext.

In text form, it looks like this (with ⟶ representing the tab character):

dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext

If we were to write this representation in code, it will look like this: "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". Note that the '\n' and '\t' are the new-line and tab characters.

Every file and directory has a unique absolute path in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by '/'s. Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". Each directory name consists of letters, digits, and/or spaces. Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.

Given a string input representing the file system in the explained format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Constraints:
* 1 <= input.length <= 104
* input may contain lowercase or uppercase English letters, a new line character '\n', a tab character '\t', a dot '.', a space ' ', and digits.

*/

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        
        // 記憶不同階層的長度，每個階層的長度都一樣
        unordered_map<size_t, int> lengthOfLevel;
        
        string temp;
        int maxLen;


        while (getline(ss, temp, '\n')) {
            // 有幾個 /t 就是第幾層，第二層的 depth 是 0
            // root 的 depth 則是 0-1 也就是 string::pos (size_t 的最大值)
            auto depth = temp.find_last_of("\t");
            string name = (depth == string::npos) ? temp : temp.substr(depth+1);
            // 如果是檔案就紀錄最大長度
            if (name.find('.') != string::npos) {
                maxLen = max(maxLen, lengthOfLevel[depth-1] + (int)name.size());
            } else {
                if (lengthOfLevel.count(depth-1))
                    lengthOfLevel[depth] = lengthOfLevel[depth-1] + name.size() + 1;
                else
                    lengthOfLevel[depth] = name.size() + 1;
            }
        }
        return maxLen;
    }
};