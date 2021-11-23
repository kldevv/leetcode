'''
Number: 299
Topic: Bulls and Cow
Date: 2021/3/25
Rate: Medium

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

'''

# time complexity O(n)
# space complexity O(1)
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        keeper = dict()

        # get the bulls and hash the secret
        for idx in range(len(secret)):
            if secret[idx] == guess[idx]:
                bulls += 1
            else:
                if secret[idx] in keeper:
                    keeper[secret[idx]] += 1
                else:
                    keeper[secret[idx]] = 1
        
        # get the cows
        for idx in range(len(guess)):
            # only consider case in the hashtable and not a bulls
            if (guess[idx] in keeper) and (guess[idx] != secret[idx]):
                if keeper[guess[idx]] > 0:
                    cows += 1
                    # decrease the hashtable count
                    keeper[guess[idx]] -= 1

        return "{bulls}A{cows}B".format(bulls=bulls, cows=cows)



