/*
Number: 294
Topic: Flip Game II
Date: 2021/7/17
Rate: Medium
https://leetcode.com/problems/flip-game-ii/

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.

Constraints:
* 1 <= currentState.length <= 60
* currentState[i] is either '+' or '-'.

Follow up: Derive your algorithm's runtime complexity.
*/

class Solution {
public:
    bool canWin(string currentState) {
        unordered_set<string> loseStat;
        return canWin(currentState, loseStat);
    }

    bool canWin(string currentState, unordered_set<string>& loseStat) {
        // 紀錄會輸的局，如果無法贏，就直接回傳會輸
        if (loseStat.count(currentState))
            return false;

        // 贏的情況只有一種，當對手無法贏時，就算贏了
        int n = currentState.size();
        for (int i = 1; i < n; i++) {
            if (currentState[i] == '+' && currentState[i-1] == '+') {
                flipState(currentState, i-1, i);
                // 當對手沒辦法翻轉，或是沒辦法封殺我們的話，就代表我們贏了
                if (!canWin(currentState, loseStat))
                    return true;
                flipState(currentState, i-1, i);
            }
        }
        // 嘗試過所有組合，要麼就是完全不能動，要麼就是無法封殺對手
        loseStat.insert(currentState);
        return false;
    }

    void flipState(string& currentState, int start, int end) {
        while (start <= end) {
            if (currentState[start] == '+')
                currentState[start++] = '-';
            else
                currentState[start++] = '+';
        }
    }
};