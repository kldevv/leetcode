/*
Number: 332
Topic: Reconstruct Itinerary
Date: 2021/12/2
Rate: Hard
https://leetcode.com/problems/trapping-rain-water/

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
    * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Constraints:
    * 1 <= tickets.length <= 300
    * tickets[i].length == 2
    * fromi.length == 3
    * toi.length == 3
    * fromi and toi consist of uppercase English letters.
    * fromi != toi
*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
        trans = [from, to]

        citiesLogs (results)
        ticketVisited[string] = numberOfTicket
        neighborCity[from] = [to.......]

        From city (A):
            store B to citiesLogs

            Base Case:
                If len(citiesLogs) == len(tickets)

            For city (B) connected to city (A):
                if "A->B" not in ticketVisited or ticketVisited["A->B"] <= 0:
                    continue
                ticketVisited["A->B"] -= 1

                result = Recur -> From city(B):
                if result = success:
                    return true

                ticketVisited["A->B"] += 1

            pop B
            return fail
        */
        unordered_map<string, vector<string>> neighborCities;
        unordered_map<string, int> ticketSignatureCount;
        int numOfTicket = 0;

        for (vector<string> tick : tickets) {
            string ori = tick[0];
            string dest = tick[1];

            neighborCities[ori].push_back(dest);
            ticketSignatureCount[ori + "$" + dest] += 1;
            numOfTicket += 1;
        }

        for (pair<string, vector<string>>&& connection : neighborCities) {
            vector<string> neighbors = connection.second;
            sort(neighbors.begin(), neighbors.end());
            neighborCities[connection.first] = neighbors;
        }

        vector<string> citiesLogs;
        if (findItinerary("JFK", neighborCities, ticketSignatureCount, citiesLogs, numOfTicket))
            return citiesLogs;

        return vector<string>();
    }

    bool findItinerary(string oriCity, unordered_map<string, vector<string>>& neighborCities, unordered_map<string, int>& ticketSignatureCount, vector<string>& citiesLogs, int& numOfTicket) {
        citiesLogs.push_back(oriCity);

        if (citiesLogs.size() == numOfTicket + 1)
            return true;

        for (string destCity : neighborCities[oriCity]) {
            if (ticketSignatureCount[oriCity + "$" + destCity] <= 0)
                continue;
            ticketSignatureCount[oriCity + "$" + destCity] -= 1;
            if (findItinerary(destCity, neighborCities, ticketSignatureCount, citiesLogs, numOfTicket))
                return true;
            ticketSignatureCount[oriCity + "$" + destCity] += 1;
        }
        citiesLogs.pop_back();
        return false;
    }
};
