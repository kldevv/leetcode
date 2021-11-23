/*
Number: 332
Topic: Reconstruct Itinerary
Date: 2021/7/7
Rate: Medium
https://leetcode.com/problems/reconstruct-itinerary/

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


Constraints:
* 1 <= tickets.length <= 300
* tickets[i].length == 2
* fromi.length == 3
* toi.length == 3
* fromi and toi consist of uppercase English letters.
* fromi != toi

*/


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> umap;
        int n = 1;

        // 先儲存一個 adjacent list
        for (vector<string>& ticket : tickets) {
            umap[ticket[0]].push_back(ticket[1]);
            // 順便計算要去少個點
            n += 1;
        }

        for (auto& p : umap) {
            // lexicographical ordered
            sort(p.second.begin(), p.second.end());
        }

        vector<string> out;
        traverseDFS(umap, "JFK", out, n);

        return out;
    }

    bool traverseDFS(unordered_map<string, deque<string>>& umap, string key, vector<string>& out, int& n) {
        if (out.size() == n-1) {
            // 如果只剩最後一個地點，就回傳成功
            out.push_back(key);
            return true;
        }

        // 如果是死胡同就回傳 false
        if (!umap.count(key) || umap[key].empty())
            return false;

        // 不斷嘗試可能的行程點，嘗試完這層所有的行程之後，表示目前這個 key 無法達到任何答案，回傳 false
        for (int i = 0; i < umap[key].size(); i++) {
            out.push_back(key);
            string next = umap[key].front();
            umap[key].pop_front();

            // 如果有地方回傳 true 就代表這條路是可行
            if (traverseDFS(umap, next, out, n))
                return true;

            // 不行的話就 pop 掉
            out.pop_back();
            umap[key].push_back(next);
        }
        return false;
    }
};