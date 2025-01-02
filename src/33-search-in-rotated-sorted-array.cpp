#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int search(vector<int>& nums, int target) 
        {
            int left = 0, right = nums.size() - 1;

            while(left <= right)
            {
                int mid = left + (right - left ) / 2;

                
                if(nums[mid] == target)
                {
                    return mid;
                }

                if(nums[mid] >= nums[left])
                {
                    if(nums[mid] >= target && target >= nums[left])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                else
                {
                    if(nums[mid] <= target && target <= nums[right])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }

            return -1;
        }
};

int main()
{
    vector<vector<int>> inputs 
    { 
        {4,5,6,7,0,1,2},
        {4,5,6,7,0,1,2},
        {1}
    };

    vector<int> targets
    {
        0,
        3,
        0
    };

    vector<int> outputs 
    { 
        4,
        -1,
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

But need a little upgrade due to the rotation. Ultimate goal is to find the mid index that equals the target.

Two cases are evaluated. Each case also have two subcases:

Case 1: nums[mid] >= nums[left] or left side is sorted.
    SubCase 1: target is in the left zone. 
        - Omit the right zone
    SubCase 2: Otherwise
        - Omit the left zone.
Case 2: Otherwise. That means right side is sorted.
    SubCase 1: target is in the right zone. 
        - Omit the left zone
    SubCase 2: Otherwise
        - Omit the right zone.   
*/