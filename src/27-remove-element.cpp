#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int removeElement(vector<int>& nums, int val) 
        {
            int j = 0;

            for(int i =0; i<nums.size(); i++)
            {
                if(nums[i] != val)
                {
                    nums[j] = nums[i];
                    j++;
                }
            }

            return j;
        }
};

int main()
{
    vector<vector<int>> nums
    { 
        {3,2,2,3},
        {0,1,2,2,3,0,4,2}
    };

    vector<int> val = {3,2};

    vector<vector<int>> output
    { 
        {2,2},
        {0,0,1,3,4}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int k = solution.removeElement(nums[i], val[i]);
        CustomAssert::run(output[i].size(), k, "Array size mismatch.");
        sort(nums[i].begin(), nums[i].begin() + k);
        for(int j =0; j<k; j++)
        {
            CustomAssert::run(output[i][j], nums[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
We need two pointers:
Pointer 1: Traverse the whole array.
Pointer 2: Increemnt only when you need to update the value.

The value only needs to be updated when current number is not equals to the given value. 
Otherwise only increment Pointer 1 and keep Pointer 2 unchanged.
*/