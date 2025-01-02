#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int search(vector<int>& nums, int target) 
        {
            int i = 0, j = nums.size() - 1;

            while(i<=j)
            {
                int k = i + (j - i)/2;

                if(nums[k] < target)
                {
                    i = k + 1;
                }
                else if(nums[k] > target)
                {
                    j = k - 1;
                }
                else
                {
                    return k;
                }
            }

            return -1;
        }
};


int main()
{
    vector<vector<int>> inputs 
    { 
        {-1,0,3,5,9,12},
        {-1,0,3,5,9,12},
    };

    vector<int> targets
    {
        9,
        2
    };

    vector<int> outputs 
    { 
        4,
        -1
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.search(inputs[i], targets[i]);
        CustomAssert::run<int>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Binary search.
i<=j
if(nums[k] < target)
{
i = k + 1;
}
else if(nums[k] > target)
{
j = k - 1;
}
else
{
return k;
}

Classic algorithm.
*/