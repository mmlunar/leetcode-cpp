#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int jump(vector<int>& nums) 
        {
            int n=nums.size(), l=0, r=0, jumps=0;

            while(r<n-1)
            {
                int maxGo = 0;
                for(int i=l; i<=r; i++)
                {
                    maxGo = max(maxGo, i+nums[i]);
                }
                l=r+1;
                r=maxGo;
                jumps++;
            }
            return jumps;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {2,3,1,1,4},
        {2,3,0,1,4},
    };

    vector<int> output 
    { 
        2,
        2,
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.jump(nums[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
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