// 2022/01/03

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        
        // isPal[start(inclusive)][end(exclusive)]
        vector<vector<int>> isPal(n+1, vector<int>(n+1, 0));


        for (int len = 1; len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                int end = start + len;
                if (len <= 2) {
                    isPal[start][end] = (s[start] == s[end-1]);
                } else {
                    isPal[start][end] = ((s[start] == s[end-1]) && isPal[start+1][end-1]);
                }
                result += isPal[start][end];
            }
        }
        
        return result;
    }
};

