#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"
#include <stack>

using namespace std;

// First solution
class Solution 
{
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) 
        {
            stack<int> indices;
            int n = temperatures.size();
            vector<int> warmer(n);

            for(int i=n-1; i>=0; i--)
            {
                while(!indices.empty() && temperatures[indices.top()]<=temperatures[i])
                {
                    indices.pop();
                }

                warmer[i] = indices.empty() ? 0 : indices.top() - i;
                indices.push(i);
            }

            return warmer;
        }
};

// Second solution
class Solution1
{
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) 
        {
            int n = temperatures.size(), hottest = 0;
            vector<int> warm(n);

            for(int i=n-1; i>=0;  i--)
            {
                int current = temperatures[i];

                if(current >= hottest)
                {
                    hottest = current;
                    continue;
                }

                int day = 1;

                while(day+i<n && temperatures[day+i] <= current)
                {
                    day += warm[day+i];
                }

                warm[i] = day;
            }

            return warm;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {73,74,75,71,69,72,76,73},
        {30,40,50,60},
        {30,60,90},
        {89,62,70,58,47,47,46,76,100,70}
    };

    vector<vector<int>> output 
    { 
        {1,1,4,2,1,1,0,0},
        {1,1,1,0},
        {1,1,0},
        {8,1,5,4,3,2,1,1,0,0},
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> result = solution.dailyTemperatures(nums[i]);
        int m = result.size();
        CustomAssert::run<int>(output[i].size(), m, "Array size mismatch.");

        for(int j=0; j<m; j++)
        {
            CustomAssert::run<int>(output[i][j], result[j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
A monotonic decreasing stack for the reverse iterated array can solve the problem.

The logic behind that is, at index i if temperature is t then we can ignore all 
temperatures smaller than t after i. Cause the "greater" t will satisfy warm day condition regardless of their 
values. And the topmost value of stack can satisfy the answer for index i.

There is a second approach where we do not need the stack. This one just utilizes the values of results to get the warmer day. 
The logic for this approach is like this:
1. Start with the immediate next index i.e. (i+1)-th index. If this one is warmer than your current index then answer is 1.
2. Otherwise, check the warmer day index that was mentioned by (i+1)-th index. Suppose that is j. We can ignore all other 
values between (i+1)-th and j-th cause we know that they are nor warmer.
3. This iteration will eventually provide the result and similar way we can finish the entire array.

Second approach also makes sure that the time complexity is O(n). Cause, the iteration is similar to accessing a stack where an
element is inserted or removed only at most once. As a result max iteration possible is O(2n) which is actually O(n).
*/