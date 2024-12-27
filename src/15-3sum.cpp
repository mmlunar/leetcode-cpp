#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    private:
        vector<vector<int>> triplets;
        int n;

        void twoSum(vector<int>& nums, int start, int target, int num)
        {
            int i = start, j = n-1;

            while(i<j)
            {
                int sum = num + nums[i] + nums[j];
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
                    triplets.push_back({num, nums[i], nums[j]});
                    i++;
                    j--;
                    while (i < j && nums[i] == nums[i - 1]) 
                    {
                        i++;
                    }
                }
            }
        }
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            int target = 0;
            this->n = nums.size();

            for(int i=0; i<n; i++)
            {
                if(nums[i] > target)
                {
                    break;
                }

                if (i > 0 && nums[i] == nums[i - 1]) 
                {
                    continue;
                }

                twoSum(nums, i+1, target, nums[i]);
            }

            return triplets;
        }

        void clear()
        {
            triplets.clear();
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
        {-1,0,1,2,-1,-4},
        {0,1,1},
        {0,0,0}
    };

    vector<vector<vector<int>>> output
    { 
        {{-1,-1,2},{-1,0,1}},
        {},
        {{0,0,0}}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<vector<int>> result = solution.threeSum(input[i]);
        sortVectorOfVectors(result);
        int sz = result.size();
        CustomAssert::run<int>(output[i].size(), sz, "Size mismatch.");
        for(int j=0;j<sz;j++)
        {
            CustomAssert::run<int>(output[i][j][0], result[j][0], "First index mismatch.");
            CustomAssert::run<int>(output[i][j][1], result[j][1], "Second index mismatch.");
            CustomAssert::run<int>(output[i][j][2], result[j][2], "Third index mismatch.");
        }
        solution.clear();
    }

    cout<<"All tests passed!";

    return 0;
}

/*
For, 3Sum, the sorted two sum problem will be our friend. Therefore, we have to sort the array first.

Then take a number and solve two sum problem for the rest. For example, for a number n and target t, 
the rest part of the array need to be solved for the two sum. Then the two sum result combined with n 
will provide three sum output.
*/