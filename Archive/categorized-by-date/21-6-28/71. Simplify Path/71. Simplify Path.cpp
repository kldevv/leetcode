/*
Number: 71
Topic: Simplify Path
Date: 2021/6/28
Rate: Medium
https://leetcode.com/problems/simplify-path/

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

* The path starts with a single slash '/'.
* Any two directories are separated by a single slash '/'.
* The path does not end with a trailing '/'.
* The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

Return the simplified canonical path.

Constraints:
* 1 <= path.length <= 3000
* path consists of English letters, digits, period '.', slash '/' or '_'.
* path is a valid absolute Unix path.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;

        if (path[path.size()-1] != '/')
            path += '/';
        int j = 1;
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (path[i-1] == '/' || i-j == 1 && path[i-1] == '.') {
                    j = i+1;
                    continue;
                }
                
                if (i-j == 2 && path[i-1] == '.' && path[i-2] == '.') {
                    if (!stk.empty())
                        stk.pop();
                } else {
                    stk.push(path.substr(j, i-j));
                }

                j = i+1;
            }
        }

        string out = (stk.empty()) ? "/" : stk.top();
        if (!stk.empty())
            stk.pop();
        while (!stk.empty()) {
            string s = stk.top();
            s += "/" + out;
            out = s;
            stk.pop();
        }

        return (out == "/") ? out : "/" + out;
    }
};