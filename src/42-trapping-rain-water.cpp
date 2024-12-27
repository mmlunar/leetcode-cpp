#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution1 
{
    public:
        int trap(vector<int>& height) 
        {
            int i=0, j=height.size()-1, maxLeft = height[i], maxRight = height[j], water = 0;

            while(i<j)
            {
                if(maxLeft <= maxRight)
                {
                    i++;
                    maxLeft= max(maxLeft, height[i]);
                    water += maxLeft - height[i];
                }
                else
                {
                    j--;
                    maxRight= max(maxRight, height[j]);
                    water += maxRight - height[j];
                }
            }

            return water;
        }
};

class Solution2 
{
    public:
        int trap(vector<int>& height) 
        {
            int i=0, j=height.size()-1, maxLeft = height[i], maxRight = height[j], water = 0;

            while(i<=j)
            {
                if(maxLeft <= maxRight)
                {
                    water += max(maxLeft - height[i], 0);
                    maxLeft= max(maxLeft, height[i]);
                    i++;
                }
                else
                {
                    water += max(maxRight - height[j], 0);
                    maxRight= max(maxRight, height[j]);
                    j--;
                }
            }

            return water;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {4,2,0,3,2,5},
        {5,5,1,7,1,1,5,2,7,6}
    };

    vector<int> output 
    { 
        6,
        9,
        23
    };

    int n = output.size();

    Solution1 solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.trap(nums[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The trick is to calculate individual water consumption on top of the each bar. It depends on eaith maxLeft 
or maxRight bar height of that specific bar. We need to iterated from left or right based on the minimum 
maxLeft and maxRight values and then iterated for the next step.

I have provide two versions of implementation. Solution one is more efficient but Solution two is more 
intuitive. Although both have the same time and space complexity.
*/