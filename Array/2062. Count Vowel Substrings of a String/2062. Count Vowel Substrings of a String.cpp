/*
Number: 2062
Topic: Count Vowel Substrings of a String
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/count-vowel-substrings-of-a-string/

A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

Constraints:
    * 1 <= word.length <= 100
    * word consists of lowercase English letters only.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countVowelSubstrings(string word) {
        /*
        Exactly(k) = AtMost(k) - AtMost(k-1)

        %%%%%%%%%%%%
        Complexity
        */
        return atMostK(word, 5) - atMostK(word, 4);
    }

    int atMostK(string word, int k) {
        /*
        Sliding Windows (inclusive, inclusive);
            - Actions
                - # of unique vowels
                    - countUniqueVowels
                    - countVowels
                - # of non-vowels
                    - countNonVowel
            - Valid Actions
                - record the # of subarrays end in $tail
                - move tail
            - Invalid Actions (countUniqueVowels > k || countNonVowel > 0)
                - move head
        */
        int head = 0;
        int tail = 0;
        vector<int> countVowels(5, 0);
        int countUniqueVowels = 0;
        int countNonVowel = 0;
        int countValidArr = 0;
        char c;

        for (; tail < word.size(); tail++) {
            c = word[tail];
            if (isVowel(c))
                countUniqueVowels += (!countVowels[mapVowelToIdx(c)]++);
            else
                countNonVowel += 1;

            while (head <= tail && (countUniqueVowels > k || countNonVowel > 0)) {
                c = word[head++];
                if (isVowel(c))
                    countUniqueVowels -= (!--countVowels[mapVowelToIdx(c)]);
                else
                    countNonVowel -= 1;
            }
            countValidArr += (tail - head + 1);
        }
        return countValidArr;
    }
    bool isVowel(char c) {
        return (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u');
    }

    int mapVowelToIdx(char c) {
        switch (c) {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
            default:
                break;
        }
        return -1;
    }
};