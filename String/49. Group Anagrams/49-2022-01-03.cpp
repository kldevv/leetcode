class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> group;
        for (string s : strs) {
            group[hashStr(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (auto p : group) {
            result.push_back(p.second);
        }
        return result;
    }
    
    string hashStr(string s) {
        vector<int> counter(26, 0);
        for (char c : s) {
            counter[c-'a'] += 1;
        }
        return hashCounter(counter);
    }
    
    string hashCounter(vector<int> counter) {
        string hash = "";
        for (int i = 0; i < 26; i++) {
            hash += to_string(counter[i]) + "$";
        }
        return hash;
    }
};