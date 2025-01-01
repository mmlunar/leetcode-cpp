#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"
#include <unordered_map>
#include <map>
#include <functional>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution 
{
    private:
        map<string, function<int(int, int)>> operations;
    public:
        Solution()
        {
                operations = 
                {
                    {"+", [](int a, int b) { return a + b; }},
                    {"-", [](int a, int b) { return a - b; }},
                    {"*", [](int a, int b) { return a * b; }},
                    {"/", [](int a, int b) { return a / b; }}
                };
        }
        int evalRPN(vector<string>& tokens)
        {
            unordered_set<string> expressions = {"+", "-", "*", "/"};
            stack<int> values;

            for(string& s: tokens)
            {
                if(expressions.find(s) == expressions.end())
                {
                    values.push(stoi(s));
                }
                else
                {
                    int a = values.top();
                    values.pop();
                    int b = values.top();
                    values.pop();
                    values.push(operations[s](b,a));
                }
            }

            return values.top();
        }
};

int main()
{
    vector<vector<string>> inputs 
    { 
        {"2","1","+","3","*"},
        {"4","13","5","/","+"},
        {"10","6","9","3","+","-11","*","/","*","17","+","5","+"},
    };

    vector<int> outputs 
    { 
        9,
        6,
        22
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.evalRPN(inputs[i]);

        CustomAssert::run<int>(outputs[i], result, "Output mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Using stack can make this problem very simple.

Just handling expressions become efficient if we use a map of string to function with functional lib.


*/