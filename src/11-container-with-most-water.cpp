#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int i=0, j= height.size()-1, maxArea= 0;

            while(i<j)
            {
                maxArea = max(maxArea, min(height[i], height[j])*(j-i));

                if(height[i] < height[j])
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }

            return maxArea;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {1,8,6,2,5,4,8,3,7},
        {1,1},
    };

    vector<int> output 
    { 
        49,
        1,
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.maxArea(nums[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Greedy & two pointer together!

Start from two end then approach to the next step based on lower height. 
Cause that will only create an opportunity to get a better area.
Calculate area in each step and take the max.
*/