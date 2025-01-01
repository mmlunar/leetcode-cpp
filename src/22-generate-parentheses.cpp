#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
    private:
        vector<string> combinations;
        void generate(string s, int front, int back)
        {
            if(front == 0 && back == 0)
            {
                combinations.push_back(s);
                return;
            }

            if(front == back)
            {
                s.push_back('(');
                generate(s, front-1, back);
            }
            else if(front == 0)
            {
                s.push_back(')');
                generate(s, front, back-1);
            }
            else
            {
                s.push_back('(');
                generate(s, front-1, back);
                s.pop_back();
                s.push_back(')');
                generate(s, front, back-1);               
            }
        }
    public:
        vector<string> generateParenthesis(int n) 
        {
            string s;
            generate(s, n, n);

            return combinations;
        }

        void clear()
        {
            combinations.clear();
        }
};

int main()
{
    vector<int> inputs 
    { 
       3,
       1,
       5
    };

    vector<vector<string>> outputs 
    { 
        {"((()))","(()())","(())()","()(())","()()()"},
        {"()"},
        {"((((()))))","(((()())))","(((())()))","(((()))())","(((())))()","((()(())))","((()()()))","((()())())","((()()))()","((())(()))","((())()())","((())())()","((()))(())","((()))()()","(()((())))","(()(()()))","(()(())())","(()(()))()","(()()(()))","(()()()())","(()()())()","(()())(())","(()())()()","(())((()))","(())(()())","(())(())()","(())()(())","(())()()()","()(((())))","()((()()))","()((())())","()((()))()","()(()(()))","()(()()())","()(()())()","()(())(())","()(())()()","()()((()))","()()(()())","()()(())()","()()()(())","()()()()()"}
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<string> result = solution.generateParenthesis(inputs[i]);

        sort(result.begin(), result.end());

        int m = result.size();

        for(int j=0; j<m; j++)
        {
            CustomAssert::run<string>(outputs[i][j], result[j], "Output mismatch.");
        }

        solution.clear();
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Backtracking can solve the problem most intuitively.

For valid parenthesis set we need to keep in mind two things:
(1) When open and close parenthesis numbers are equal then we can only generate valid sequence by open parenthesis only.
(2) Open parenthesis is greater than close parenthesis then we can add both types to generate valid sequence.

Based on these two assumptions we need to write the backtrack logic. That's it.
*/