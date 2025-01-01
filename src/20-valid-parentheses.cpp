#include <iostream>
#include <string>
#include "CustomAssert.h"
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class Solution 
{
    public:
        bool isValid(string s) 
        {
            unordered_map<char, char> closeToOpen = {{')', '('}, {'}', '{'}, {']', '['}};
            stack<char> container;

            for(char& c: s)
            {
               if(closeToOpen.count(c))
               {
                    if(!container.empty() && container.top() == closeToOpen[c])
                    {
                        container.pop();
                    }
                    else
                    {
                        return false;
                    }
               }
               else
               {
                    container.push(c);
               }
            }

            return container.empty();
        }
};

int main()
{
    vector<string> s 
    { 
        "()",
        "()[]{}",
        "(]",
        "([])",
        "["
    };

    vector<bool> output 
    { 
        true,
        true,
        false,
        true,
        false
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.isValid(s[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Straightforward approach.

But, need to plan for a systematic approach. Otherwise, your code might be messy.

The logic appled here:

1. If it is open then put it in the stack and no further action is necessary.

2. Otherwise:
    i. If stack is non empty and top stack char corresponds the current char:
        continue after poping the stack
    ii. Otherwise return false

/Finally chgeck if stack is empty otherwise return false.
*/