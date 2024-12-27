#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            int i=0, j=numbers.size()-1;

            while(i<j)
            {
                if(numbers[i] + numbers[j] < target)
                {
                    i++;
                }
                else if(numbers[i] + numbers[j] > target)
                {
                    j--;
                }
                else
                {
                    return {i+1,j+1};
                }
            }

            return {};
        }
};

int main()
{
    vector<vector<int>> input
    { 
        {2,7,11,15},
        {2,3,4},
        {-1,0}
    };

    vector<int> target 
    { 
        9,
        6,
        -1,
    };

    vector<vector<int>> output
    { 
        {1,2},
        {1,3},
        {1,2}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> result = solution.twoSum(input[i], target[i]);
        CustomAssert::run<int>(2, result.size(), "Output should be a 1x2 vector.");
        CustomAssert::run<int>(output[i][0], result[0], "First index mismatch.");
        CustomAssert::run<int>(output[i][1], result[1], "Second index mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
A standard two pointer algorithm where we need to check the chars from each pointer.

For ignoring the non alpha numeric chars we use two while loops and then check the lowcase converted result.
*/