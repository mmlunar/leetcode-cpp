#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            if(n < 2)
            {
                return n;
            }
            int j = 2;

            for(int i=2; i<n; i++)
            {
                if(nums[j-2] != nums[i])
                {
                    nums[j] = nums[i];
                    j++;
                }
            }

            return j;
        }
};

class Solution2 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int count = 1, j = 1;

            for(int i=1; i<nums.size(); i++)
            {
                count = nums[i] == nums[i-1] ? count + 1 : 1;

                if(count <=2)
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
        {1,1,1,2,2,3},
        {0,0,1,1,1,1,2,3,3},
        {1}
    };

    vector<vector<int>> output
    { 
        {1,1,2,2,3},
        {0,0,1,1,2,3,3},
        {1}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int k = solution.removeDuplicates(nums[i]);
        CustomAssert::run<int>(output[i].size(), k, "Array size mismatch.");
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
Since all elements are sorted and we can take each element at most twice,
the best option is to check whether the current value is equals the two index
eariler values. If not only then we can add it to the array. Otherwise not.

One corner case is the array size smaller than 2. Then we can simply return without doing anything.

Alternatively(solution 2), we can count the duplicates and ignore updes when count > 2.
*/