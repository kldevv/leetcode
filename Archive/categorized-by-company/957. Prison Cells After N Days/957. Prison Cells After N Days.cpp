/*
Number: 692
Topic: Top K Frequent Words
Date: 2021/9/1
Rate: Medium
https://leetcode.com/problems/top-k-frequent-words/

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Constraints:
* 1 <= words.length <= 500
* 1 <= words[i] <= 10
* words[i] consists of lowercase English letters.
* k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> umap;
        while (n) {
            string status(cells.begin(), cells.end());
            umap[status] = n--;

            vector<int> newCells(8, 0);
            for (int i = 1; i < 7; i++)
                newCells[i] = (cells[i-1] == cells[i+1]);
            cells = newCells;
            string newStatus(cells.begin(), cells.end());

            if (umap.count(newStatus))
                n %= umap[newStatus] - n;
        }
        return cells;
    }
};