// 2022/01/03

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        vector<int> occur(256, 0);
        
        int maxLen = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (occur[s[j]]++ == 0)
                k -= 1;
            
            while (i <= j && k < 0) {
                if (--occur[s[i++]] == 0)
                    k += 1;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};