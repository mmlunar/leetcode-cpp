#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
        {
            int i = m-1, j = n-1;
            for(int k = nums1.size()-1; k >=0; k--)
            {
                if((i>=0 && j<0) || (i>=0 && nums1[i] >= nums2[j]))
                {
                    nums1[k] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    j--;
                }
            }
            
        }
};

int main()
{
    vector<vector<int>> nums1 
    { 
        {1,2,3,0,0,0},
        {1},
        {0}
    };

    vector<vector<int>> nums2
    { 
        {2,5,6},
        {},
        {1}
    };

    vector<int> m = {3, 1, 0};
    vector<int> n = {3, 0, 1};

    vector<vector<int>> output 
    { 
        {1,2,2,3,5,6},
        {1},
        {1}
    };

    int l = nums1.size();

    Solution solution;

    for(int i = 0; i<l; i++) 
    {
        solution.merge(nums1[i], m[i], nums2[i], n[i]);

        for(int j =0; j<output[i].size(); j++)
        {
            CustomAssert::run(output[i][j], nums1[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The major trick here is to start from the end. Otherwise, keeping track overwritten values will be a challenge.
Only two type of movement is possible:
Type 1: Move num1 values to num1
Type 2: Move nums values from num2

To take the right decision we need to make a perfect if condition for the Type1. Then Type2 willbe the else.

If j is -ve we have to take numbers from num1 always. In additon before comparing two arrays we need to make sure i>=0. 
If not we are good to go to the else condition.
*/