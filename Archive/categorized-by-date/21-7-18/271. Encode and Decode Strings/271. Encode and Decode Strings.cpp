/*
Number: 271
Topic: Encode and Decode Strings
Date: 2021/7/18
Rate: Hard
https://leetcode.com/problems/encode-and-decode-strings/

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

Constraints:
* 1 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] contains any possible characters out of 256 valid ASCII characters.
 

Follow up: Could you write a generalized algorithm to work on any possible set of characters?
*/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            string length = to_string(s.size());
            encoded += length + "@" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;

        int startAt = 0;
        while (startAt < s.size()) {
            int delimiterPos = s.find_first_of("@", startAt);
            int length = stoi(s.substr(startAt, delimiterPos-startAt));

            decoded.push_back(s.substr(delimiterPos+1, length));
            startAt = delimiterPos + 1 + length;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));