#include <iostream>
#include <vector>
#include <unordered_map>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int,int> numMap;
            int n = nums.size();

            for(int i=0; i<n; i++)
            {
                int diff = target - nums[i];
                if(numMap.count(diff))
                {
                    return {numMap[diff], i};
                }

                numMap[nums[i]] = i;
            }

            return {};
        }
};

int main()
{
    vector<vector<int>> input 
    { 
        {2,7,11,15},
        {3,2,4},
        {3,3}
    };

    vector<int> target
    {
        9,
        6,
        6
    };

    vector<vector<int>> output 
    {
        {0,1},
        {1,2},
        {0,1}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> result = solution.twoSum(input[i], target[i]);
        CustomAssert::run<int>(result.size(), 2, "Array size mismatch.");

        for(int j =0; j<2; j++)
        {
            CustomAssert::run(output[i][j], result[j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Two pointer is the key.
Pointer 1: Traverse the whole array.
Pointer 2: Increemnt only when you need to update the value.

The value only needs to be updated when current number is not equals to the immediately previous number. 
Cause only then we can say that we have a new value.
*/