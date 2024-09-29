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
For this problem, one important point is:

- We do not need to wait for the price to go at peak. For example: prices = [1,2,3]. 
We can sell when price is 2 and then add addiitonal profit in the next step. That means, we just need
to keep eye on the previous value. If it's smaller than current vlaue then add it as a profit. 
Just imagine you are selling and then buying it again in case you have additional gain in the next stage.
*/