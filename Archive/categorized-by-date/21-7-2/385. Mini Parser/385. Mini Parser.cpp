/*
Number: 385
Topic: Mini Parser
Date: 2021/7/2
Rate: Medium
https://leetcode.com/problems/mini-parser/

Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.

Each element is either an integer or a list whose elements may also be integers or other lists.

Constraints:
* 1 <= s.length <= 5 * 104
* s consists of digits, square brackets "[]", negative sign '-', and commas ','.
* s is the serialization of valid NestedInteger.

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // 照抄 pochmann 的
    // see post: https://leetcode.com/problems/mini-parser/discuss/86060/Python-and-C%2B%2B-solutions
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }

private:
    NestedInteger deserialize(istringstream& in) {
        int number;
        // 如果是 number 就直接回傳 number，並且 pop 掉最上面的數字
        if (in >> number)
            return NestedInteger(number);
        // 如果不是就 recursive call list
        in.clear();
        in.get();
        NestedInteger list;
        while (in.peek() != ']') {
            list.add(deserialize(in));
            if (in.peek() == ',') 
                in.get();
        }
        in.get();
        return list;
    }
};