#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool find132pattern(vector<int>& nums) 
        {
            stack<pair<int,int>> decreasing;
            int n = nums.size(), currentMin = INT_MAX;

            for(int i=0; i<n; i++)
            {
                while(!decreasing.empty() && decreasing.top().first <= nums[i])
                {
                    decreasing.pop();
                }

                if(!decreasing.empty() && decreasing.top().second < nums[i])
                {
                    return true;
                }

                currentMin = min(nums[i], currentMin);

                decreasing.push({nums[i], currentMin});
            }

            return false;
        }
};


int main()
{
    vector<vector<int>> inputs 
    { 
        {1,2,3,4},
        {3,1,4,2},
        {-1,3,2,0},
        {3,5,0,3,4},
        {1,0,1,-4,-3}
    };

    vector<bool> output 
    { 
        false,
        true,
        true,
        true,
        false
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.find132pattern(inputs[i]);
        CustomAssert::run<bool>(result, output[i], "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The solution approach of this problem is little tricky and difficult to get if not seen the problem before.

The trick we applied ther is in the 1-3-2 pattern we are targetting "2". That menas the last value of the subsequence.

Now we need to find "3" and "1". 

For finding "3" we are mainitianing a monotonic strictly decreasing stack. 
This stack entries the last value and then checks whether it's immediate greater value 
has a minimum value upto "3"'s postion that is also smaller than "2". Then we can take that minimum 
as "1". Once we find them all we return true. Otherwise we return false in the end.
*/