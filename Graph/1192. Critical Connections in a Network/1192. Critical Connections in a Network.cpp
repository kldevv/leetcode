/*
Number: 1192
Topic: Critical Connections in a Network
Date: 2021/9/29
Rate: Hard
https://leetcode.com/problems/critical-connections-in-a-network/

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Constraints:
    * 2 <= n <= 105
    * n - 1 <= connections.length <= 105
    * 0 <= ai, bi <= n - 1
    * ai != bi
    * There are no repeated connections.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>(0, 0));

        unordered_set<string> connects;
        for (vector<int>& connect : connections) {
            connects.insert({to_string(min(connect[0], connect[1])) + "/" + to_string(max(connect[0], connect[1]))});
            graph[connect[0]].push_back(connect[1]);
            graph[connect[1]].push_back(connect[0]);
        }

        vector<int> ranks(n, -1);
        findCycle(0, 0, connects, graph, ranks);
        
        vector<vector<int>> results;
        for (string connect : connects){
            int delimiter = connect.find('/');
            results.push_back({stoi(connect.substr(0, delimiter)), stoi(connect.substr(delimiter+1))});
        }
        return results;
    }

    int findCycle(int i, int rank, unordered_set<string>& connects, vector<vector<int>>& graph, vector<int>& ranks) {
        if (ranks[i] != - 1)
            return ranks[i];
        ranks[i] = rank;

        int minRank = INT_MAX;
        for (int neighbor : graph[i]) {
            if (ranks[neighbor] != -1 && ranks[neighbor] == rank - 1)
                continue;
            int returnRank = findCycle(neighbor, rank+1, connects, graph, ranks);
            if (returnRank <= rank)
                connects.erase(to_string(min(neighbor, i)) + "/" + to_string(max(neighbor, i)));
            minRank = min(minRank, returnRank);
        }
        return minRank;
    }
};
