#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size(), n = matrix[0].size(), i = 0, j = m*n-1;

            while(i <= j)
            {
                int k = i + (j - i)/2;
                int r = k/n;
                int c = k%n;

                if(matrix[r][c] < target)
                {
                    i = k + 1;
                }
                else if(matrix[r][c] > target)
                {
                    j = k - 1;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
};

class Solution1 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int m = matrix.size(), n = matrix[0].size(), top = 0, bottom = m - 1, left = 0, right = n - 1, mid;

            while(top <= bottom)
            {
                mid = top + (bottom - top)/2;

                if(matrix[mid][n-1] < target)
                {
                    top = mid + 1;
                }
                else if(matrix[mid][0] > target)
                {
                    bottom = mid - 1;
                }
                else
                {
                    break;
                }
            }

            int row = mid;

            while(left <= right)
            {
                mid = left + (right - left)/2;

                if(matrix[row][mid] < target)
                {
                    left = mid + 1;
                }
                else if(matrix[row][mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return true;
                }
            }

            return false;
        }
};


int main()
{
    vector<vector<vector<int>>> inputs 
    { 
        {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
        {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
    };

    vector<int> targets
    {
        3,
        13
    };

    vector<bool> outputs 
    { 
        true,
        false
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.searchMatrix(inputs[i], targets[i]);
        CustomAssert::run<bool>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Binary search.
i<=j
if(nums[k] < target)
{
i = k + 1;
}
else if(nums[k] > target)
{
j = k - 1;
}
else
{
return k;
}

Classic algorithm.
*/