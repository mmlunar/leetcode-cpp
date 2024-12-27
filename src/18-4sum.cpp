#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"
#include <cstdint>

using namespace std;

class Solution 
{
    private:
        int n;
        vector<vector<int>> validSets;

        void twoSum(vector<int>& nums, int64_t target, vector<int>& current, int start)
        {
            int i = start, j = n-1;

            while(i<j)
            {
                int sum = nums[i] + nums[j];

                if(sum < target)
                {
                    i++;
                }
                else if(sum > target)
                {
                    j--;
                }
                else
                {
                    current.push_back(nums[i]);
                    current.push_back(nums[j]);
                    validSets.push_back(current);
                    current.pop_back();
                    current.pop_back();
                    i++;
                    j--;
                    while(i<j && nums[i-1]==nums[i])
                    {
                        i++;
                    }
                }
            }
        }

        void nSum(vector<int>& nums, int64_t target, vector<int>& current, int order, int start)
        {
            if (order==2)
            {
                twoSum(nums,target, current, start);
                return;
            }

            for(int i=start; i<n; i++)
            {
                if(i>start && nums[i-1]==nums[i])
                {
                    continue;
                }

                current.push_back(nums[i]);
                nSum(nums, target - nums[i], current, order-1, i+1);
                current.pop_back();
            }            
        }
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            sort(nums.begin(),nums.end());
            this->n = nums.size();
            vector<int> current={};
            nSum(nums, target, current, 4, 0);
            return validSets;
        }

        void clear()
        {
            validSets.clear();
        }
};

// Function to sort both inner and outer vectors
void sortVectorOfVectors(std::vector<std::vector<int>>& vec) 
{
    // // Sort each inner vector lexicographically
    // for (auto& innerVec : vec) 
    // {
    //     std::sort(innerVec.begin(), innerVec.end());
    // }

    // Sort the outer vector based on the first element of each inner vector
    std::sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) 
    {
        return a[0] < b[0];  // Sort by the first int in each inner vector
    });
}


int main()
{
    vector<vector<int>> input
    { 
        {1,0,-1,0,-2,2},
        {2,2,2,2,2},
        {1,-2,-5,-4,-3,3,3,5},
        {1000000000,1000000000,1000000000,1000000000}
    };

    vector<int> target
    {
        0,
        8,
        -11,
        -294967296
    };

    vector<vector<vector<int>>> output
    { 
        {{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}},
        {{2,2,2,2}},
        {{-5,-4,-3,1}},
        {}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<vector<int>> result = solution.fourSum(input[i], target[i]);
        sortVectorOfVectors(result);
        int sz = result.size();
        CustomAssert::run<int>(output[i].size(), sz, "Size mismatch.");
        for(int j=0;j<sz;j++)
        {
            CustomAssert::run<int>(output[i][j][0], result[j][0], "First index mismatch.");
            CustomAssert::run<int>(output[i][j][1], result[j][1], "Second index mismatch.");
            CustomAssert::run<int>(output[i][j][2], result[j][2], "Third index mismatch.");
            CustomAssert::run<int>(output[i][j][3], result[j][3], "Fourth index mismatch.");
        }
        solution.clear();
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Very similar to solution of 3Sum. But this time we made it a generic solution where based on order any kSum problem could be solved.

For that, we use a recursive fuction that recurse from order to order-1 by reducing the target t to t-n for a given number. 
The fuction continues to do that until order 2 comes. Then it calls two sum and finishes the iteration.
*/