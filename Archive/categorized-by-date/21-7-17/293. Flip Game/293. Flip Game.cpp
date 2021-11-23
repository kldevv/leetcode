/*
Number: 293
Topic: Flip Game
Date: 2021/7/17
Rate: Easy
https://leetcode.com/problems/flip-game/

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return all possible states of the string currentState after one valid move. You may return the answer in any order. If there is no valid move, return an empty list [].

Constraints:
* 1 <= currentState.length <= 500
* currentState[i] is either '+' or '-'.
*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> out;
        int n = currentState.size();

        for (int i = 1; i < n ; i++) {
            if (currentState[i-1] == '+' && currentState[i] == '+') {
                flipState(currentState, i-1, i);
                out.push_back(currentState);
                flipState(currentState, i-1, i);
            }
        }
        return out;
    }

    void flipState(string& currentState, int start, int end) {
        while (start <= end) {
            if (currentState[start] == '+') {
                currentState[start++] = '-';
            }
            else
                currentState[start++] = '+';
        }
    }
};