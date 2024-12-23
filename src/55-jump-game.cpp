#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool canJump(vector<int>& nums) 
        {
            int maxDest = 0, n = nums.size();

            for(int i=0; i<n-1; i++)
            {
                if(maxDest < i)
                {
                    return false;
                }

                maxDest = max(maxDest, nums[i]+i);
            }

            return maxDest >= n-1;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {2,3,1,1,4},
        {3,2,1,0,4},
        {1,2},
        {1,2,3},
    };

    vector<bool> output 
    { 
        true,
        false,
        true,
        true,
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.canJump(nums[i]);
        CustomAssert::run<bool>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Greedy approach works to solve this problem.

Each step we can calculate the maximum distance i.e. maxDest we can jump based on 2 info:
1) Max distance at this moment a.k.a. maxDest
2) Max we can go from current position i.e. (current position + current jump steps) or (i + nums[i])

The max of 1 & 2 will be the maxDest.

Now if maxDest is smaller than current position then we have to stop and declare it's not possible. That means return false.

In then end if maxDest is greater than or equals last step i.e n-1 then return true.
*/