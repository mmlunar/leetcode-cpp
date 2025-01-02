#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int findMin(vector<int>& nums) 
        {
            int minVal = INT_MAX, left = 0, right = nums.size() - 1;

            while(left <= right)
            {
                int mid = left + (right - left) / 2;

                if(nums[mid] >= nums[left])
                {
                    minVal = min(minVal, nums[left]);
                    left = mid + 1;
                }
                else
                {
                    minVal = min(minVal, nums[mid]);
                    right = mid - 1;
                }
            }

            return minVal;
        }
};

int main()
{
    vector<vector<int>> inputs 
    { 
        {3,4,5,1,2},
        {4,5,6,7,0,1,2},
        {11,13,15,17}
    };

    vector<int> outputs 
    { 
        1,
        0,
        11
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.findMin(inputs[i]);
        CustomAssert::run<int>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Binary search.

But need a little upgrade due to the rotation.

Two cases are evaluated:

(1) If nums[left] is smaller than (or equal) nums[mid]
    Then in this half the minimum is nums[left].
    Take that and then go ahead for the remaining half (right half).
(2) Otherwise take nums[mid] for comparison with the minimum. May be it's the breaking point of the rotation.
    Then take the left half since this part is not sorted at this moment.
*/