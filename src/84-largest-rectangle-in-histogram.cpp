#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "CustomAssert.h"
#include <stack>

using namespace std;

class Solution 
{
    public:
        int largestRectangleArea(vector<int>& heights) 
        {
            int n = heights.size(), maxArea = 0;
            stack<pair<int,int>> histContainer;

            for(int i=0; i<n; i++)
            {
                int idx = i;
                while(!histContainer.empty() && histContainer.top().first > heights[i])
                {
                    idx = histContainer.top().second;
                    maxArea = max(maxArea, histContainer.top().first*(i-idx));
                    histContainer.pop();        
                }
                histContainer.push({heights[i], idx});
            }

            while(!histContainer.empty())
            {
                maxArea = max(maxArea, histContainer.top().first*(n-histContainer.top().second));
                histContainer.pop();
            }

            return maxArea;
        }
};


int main()
{
    vector<vector<int>> inputs 
    { 
        {2,1,5,6,2,3},
        {2,4},
    };

    vector<int> outputs 
    { 
        10,
        4
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.largestRectangleArea(inputs[i]);
        CustomAssert::run<int>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*

Monotonic strictly increasing stack can make the trick.

In the stack keep height and index. When a new value arrives that is not strictly increasing then pop the stack. Before popping you 
need to calculate the are until that index and update the max.

n the end do the same for last index until stack is completely empty.


*/