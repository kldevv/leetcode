// 2021/12/30
#include <cctype>
#include <string>

using namespace std;


// T(n) = Catalan number
// ref: https://people.math.sc.edu/howard/Classes/554b/catalan.pdf
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToCompute(expression, 0, expression.size());
    }

    vector<int> diffWaysToCompute(string& e, int start, int end) {
        // start inclusive
        // end exclusive
        vector<int> results;
        for (int i = start; i < end; i++) {
            if (ispunct(e[i])) {
                vector<int> left = diffWaysToCompute(e, start, i);
                vector<int> right = diffWaysToCompute(e, i+1, end);

                for (int n1 : left) {
                    for (int n2 : right) {
                        results.push_back(cal(n1, n2, e[i]));
                    }
                }
            }
        }

        if (results.empty()) {
            return vector<int> { stoi(e.substr(start, end-start)) };
        }
        return results;
    }

    int cal(int n1, int n2, char op) {
        switch (op) {
            case '+':
                return n1 + n2;
                break;
            case '-':
                return n1 - n2;
                break;
            default:
                return n1 * n2;
        }
    }
};