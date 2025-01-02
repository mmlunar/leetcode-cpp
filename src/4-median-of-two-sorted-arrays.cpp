#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            if(nums1.size() > nums2.size())
            {
                swap(nums1, nums2);
            }
            
            int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2, left = 0, right = n1;

            while(left <= right)
            {
                int mid1 = left + (right - left) / 2;
                int mid2 = (n + 1) /2 - mid1;
                int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
                int l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;
                int r1 =  mid1 < n1 ? nums1[mid1] : INT_MAX;
                int r2 =  mid2 < n2 ? nums2[mid2] : INT_MAX;

                if(l1 > r2)
                {
                    right = mid1 - 1;
                }
                else if(l2 > r1)
                {
                    left = mid1 + 1;
                }
                else
                {
                    if(n%2)
                    {
                        return (double)max(l1, l2);
                    }
                    
                    return (double)(max(l1, l2) + min(r1, r2))/2.0;   
                }
            }

            return NULL;
        }
};


int main()
{
    vector<pair<vector<int>, vector<int>>> nums 
    { 
        {{1, 3}, {2}},
        {{1, 2}, {3, 4}},
    };

    vector<double> outputs = {2, 2.5};

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        double result = solution.findMedianSortedArrays(nums[i].first, nums[i].second);
        CustomAssert::run<double>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Divide and Conquer based binary search.

Two arrays. So we need to make sure that we can split them in the combined array's mid.

For the combined median, we consider left half focused approach. Also we are working on smaller array first.

For the left half focused approach, we take right = n1 (instead of right = n1 - 1). Aslo mid2 = (n + 1) /2 - mid1 (instead of n/2).

Then we take the next element for the both array as r1 and r2. 

Our bormal expectation is: l1 <= r1 and l2 <= r2. If that happens then we are done. Cause we already splitted them in equal.

But if any of the above two conditions does not hold then we have to search again. 

When l1 > r2:
    - left side needs to be analyzed for a smaller l1 value. Therefore, right = mid1 - 1.

When l2 > r1:
    - right side needs to be analyzed for a larger r1 value. Therefore, left = mid1 + 1.

For index OOB, l1&l2 -> INT_MIN; r1&r2 -> INT_MAX. So that we can get right most l and leftmost r easily.

*/