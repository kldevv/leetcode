// 2022/01/03
#include <stack>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s.size() == 1 && ispunct(s[0])) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (s[0]) {
                    case '+':
                        stk.push(a + b);
                        break;
                    case '-':
                        stk.push(a - b);
                        break;
                    case '/':
                        stk.push(a / b);
                        break;
                    default:
                        stk.push(a * b);
                        break;
                }
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};