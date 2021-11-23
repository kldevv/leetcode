/*
Number: 1268
Topic: Search Suggestions System
Date: 2021/8/25
Rate: Medium
https://leetcode.com/problems/search-suggestions-system/

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

Constraints:
* 1 <= products.length <= 1000
* There are no repeated elements in products.
* 1 <= Σ products[i].length <= 2 * 10^4
* All characters of products[i] are lower-case English letters.
* 1 <= searchWord.length <= 1000
* All characters of searchWord are lower-case English letters.
*/
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<string> allPrefix;
        string prefix = "";
        for (int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            allPrefix.push_back(prefix);
        }

        vector<vector<string>> results;
        int i = 0;
        for (string& prefix : allPrefix) {
            int j = products.size()-1;
            while (i < j) {
                int m = i + (j-i)/2;
                if (products[m] < prefix)
                    i = m + 1;
                else
                    j = m;
            }

            int curr = j;
            i = curr;
            vector<string> result;
            for (int k = 0; k < 3 && curr < products.size(); k++) {
                if (!(products[curr].compare(0, prefix.size(), prefix)))
                result.push_back(products[curr++]);
            }
            results.push_back(result);
        }
        return results;
    }
};