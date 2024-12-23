#include <iostream>
#include <vector>
#include <unordered_set>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool containsDuplicate(vector<int>& nums) 
        {
            unordered_set<int> numsSet;

            for(int& n : nums)
            {
                if(numsSet.count(n) == 1)
                {
                    return true;
                }
                numsSet.insert(n);
            }

            return false;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {1,2,3,1},
        {1,2,3,4},
        {1,1,1,3,3,4,3,2,4,2},
    };

    vector<bool> output 
    { 
        true,
        false,
        true,
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.containsDuplicate(nums[i]);

        CustomAssert::run<int>(output[i], result, "Output mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Hashset solves the issue.

Hashset makes it possible to check all previous elements in the array present or not in O(1) time.

As a result, we get a linear time complexity algorithm.
*/