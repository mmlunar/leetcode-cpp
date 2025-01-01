#include <iostream>
#include <vector>
#include "CustomAssert.h"
#include <stack>
#include <cstdint>

using namespace std;

class MinStack2 
{
    private:
        stack<int64_t> data;
        int64_t minValue;
    public:
        MinStack2() 
        {
        }
        
        void push(int val) 
        {
            if(data.empty())
            {
                minValue = val;
            }
            
            data.push(val - minValue);
            minValue = min(minValue, (int64_t)val);
        }
        
        void pop() 
        {
            if(data.top() < 0)
            {
                minValue = minValue - data.top();
            }

            data.pop();
        }
        
        int top()
        {
            if(data.top() < 0)
            {
                return (int)minValue;
            }

            return (int)(minValue + data.top());
        }
        
        int getMin() 
        {
            return (int)minValue;        
        }
};

class MinStack1 
{
    private:
        stack<int> data;
        stack<int> minData;
    public:
        MinStack1() 
        {
        }
        
        void push(int val) 
        {
            int minValue = minData.empty() ? INT_MAX : minData.top();
            data.push(val);
            minData.push(min(minValue, val));
        }
        
        void pop() 
        {
            data.pop();
            minData.pop();
        }
        
        int top() 
        {
            return data.top();
        }
        
        int getMin() 
        {
            return minData.top();
        }
};

int main()
{
    vector<vector<string>> inputs 
    { 
        {"MinStack","push","push","push","getMin","pop","top","getMin"},
        {"MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"}
    };

    vector<vector<vector<int>>> values
    { 
        {{},{-2},{0},{-3},{},{},{},{}},
        {{}, {2147483646},{2147483646},{2147483647},{},{},{},{},{},{},{2147483647},{},{},{-2147483648},{},{},{},{}}
    };

    vector<vector<int>> output
    {
        {NULL,NULL,NULL,NULL,-3,NULL,0,-2},
        {NULL,NULL,NULL,NULL,2147483647,NULL,2147483646,NULL,2147483646,NULL,NULL,2147483647,2147483647,NULL,-2147483648,-2147483648,NULL,2147483647}
    };

    int n = output.size();

    MinStack1 minStack;

    for(int i = 0; i<n; i++) 
    {
        int m = inputs[i].size();

        for(int j=0; j<m; j++)
        {
            if(inputs[i][j] == "MinStack")
            {
                minStack = MinStack1();
            }
            else if(inputs[i][j] == "push")
            {
                minStack.push(values[i][j][0]);
            }
            else if (inputs[i][j] == "pop")
            {
                minStack.pop();
            }
            else if (inputs[i][j] == "top")
            {
                int topResult = minStack.top();
                CustomAssert::run<int>(topResult, output[i][j], "Stack top value mismatch");
            }
            else if (inputs[i][j] == "getMin")
            {
                int minResult = minStack.getMin();
                CustomAssert::run<int>(minResult, output[i][j], "Stack min value mismatch");
            }
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Two approaches to solve this problem:

Approach 1: Add one additional stack named min Stack that keep track all minimum values at a given state. As a result getting
 minimum value will be straightforward.

Approach 2: 
One stack can be sufficient with one numeric variable (minValue). 

The variable minValue will keep track current minVAlue always. As a result getResult will be just gettng minValue.

But for push, we have to save value-minValue(current) and then we will update the minValue. Therefore, at the time of top 
we will return minVAlue if the stack top is -ve. Cause that means a new minValue is found and the updates minValue is the 
current value actually. Otherwise, we will return stack top with addition of current minValue (since we subracted it previously).

For pop we can think similar logic. 
If stack top -ve
=> Value was smaller than the MinValue at that time
=> Minvalue was updated with value since value was smaller.
=> Now we have two eqn: StackTop = value - minValuePrev and minValue = value
=> Therefore, recovering minValue will be minValue-stackTop

Otherwise:
=> minvalue is already small, so unchanged.
=> Just pop will be enough. no update in minvalue is required.


*/