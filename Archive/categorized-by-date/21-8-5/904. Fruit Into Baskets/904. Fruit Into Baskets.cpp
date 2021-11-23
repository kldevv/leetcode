/*
Number: 904
Topic: Fruit Into Baskets
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/fruit-into-baskets/

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

* You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
* Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
* Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Constraints:
* 1 <= fruits.length <= 105
* 0 <= fruits[i] < fruits.length
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int basket = 2;
        unordered_map<int, int> umap;

        int j = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (!umap[fruits[i]]++) 
                basket -= 1;

            while (j < n && basket < 0) {
                if (!(--umap[fruits[j++]]))
                    basket += 1;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};