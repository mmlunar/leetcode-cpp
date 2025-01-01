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
Theare are two approaches.

In fisrt approach, the trick is to reverse the array. Then re-reverse first k elements and the rest so that they come back to their rotated position. This trick is not very intutitive and usually does not come to mind if not known before.

In the second approach, we are roating one by one values. The only constraint is roatation can create a cycle when gcd(k,n) > 1. Therefore, we are taking an offset and incrementing it when a cycle is detected (i.e. offset == prevIdx case).
*/