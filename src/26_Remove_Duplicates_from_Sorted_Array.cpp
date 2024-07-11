#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            int j = 1;

            for(int i = 1; i < n; i++)
            {
                if(nums[i] != nums[i-1])
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
    vector<vector<int>> input 
    { 
        {1,1,2},
        {0,0,1,1,1,2,2,3,3,4}
    };

    vector<vector<int>> output 
    { 
        {1,2},
        {0,1,2,3,4}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int k = solution.removeDuplicates(input[i]);
        CustomAssert::run(output[i].size(), k, "Array size mismatch.");

        for(int j =0; j<k; j++)
        {
            CustomAssert::run(output[i][j], input[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";
}

/*
Two pointer is the key.
Pointer 1: Traverse the whole array.
Pointer 2: Increemnt only when you need to update the value.

The value only needs to be updated when current number is not equals to the immediately previous number. 
Cause only then we can say that we have a new value.
*/