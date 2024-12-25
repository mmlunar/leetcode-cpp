#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            int n = nums.size();
            vector<int> prods(n, 1);

            for(int i=1; i<n; i++)
            {
                prods[i] = prods[i-1] * nums[i-1];
            }

            int prodHelp = nums[n-1];
            for(int i=n-2; i>=0; i--)
            {
                prods[i] *= prodHelp;
                prodHelp *= nums[i];
            }

            return prods;
        }
};


int main()
{
    vector<vector<int>> nums 
    { 
        {1,2,3,4},
        {-1,1,0,-3,3}
    };

    vector<vector<int>> output 
    { 
        {24,12,8,6},
        {0,0,9,0,0}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> result = solution.productExceptSelf(nums[i]);

        int m = result.size();

         CustomAssert::run<int>(m, nums[i].size(), "Array size mismatch.");

        for(int j=0; j<m; j++)
        {
            CustomAssert::run<int>(output[i][j], result[j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The concept of prefix sum is used here as prefix product.

The overall solution has two steps.

In the first step, at i-th index we are storing prefix producct of all numbers within (i-1)-th index.

Then we take a number that start from the reverse order and collect prefix product in the reverse way. 

At each number previous prefix prod array is updated with this value since it has all products after this number.

Giving an example: {1,2,3,4,5} is the array.

For this array 2-th index has value 3. 

All numbers before 3 are multiplied and stored in the prefix product array. Therefore the 2-th index has value=2 i.e. (1*2).

Now a variable prodHelp is starting from the end and coming backwards. At 2-th index it has all numbers multiplication after the 2-th index.
That means the prodHelp=20 (i.e. 5*4). If we multiply this 20 with the first step value 2 then we get the result = 40 for 2-th index.

In short, we are collecting product of all numbers before i in the first step. The we are multiplying it with
 the number that contains products of all numbers after i.
*/