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
Greedy!

Start from the begeining and count max possible next step based on
each step we can hop from current step. Do the same for the next iteration.
After each iteration count jump as an increment of 1.
*/