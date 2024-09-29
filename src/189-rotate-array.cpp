#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

// First solution
class Solution 
{
    public:
        void rotate(vector<int>& nums, int k)
        {
            int n = nums.size();
            k = k % n; // Each n rotation takes the array to it's initial stage. 

            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        }
};

// Second solution
class Solution1 
{
    public:
        void rotate(vector<int>& nums, int k)
        {
            int offset = 0, prevIdx = 0, prevVal = nums[0], curIdx, curVal, n = nums.size();

            for(int i=0; i<n; i++)
            {
                curIdx = (prevIdx + k)%n;
                curVal = nums[curIdx];
                nums[curIdx] = prevVal;
                prevIdx = curIdx,
                prevVal = curVal;

                if(prevIdx == offset)
                {
                    prevIdx++;
                    offset++;
                    prevVal = nums[prevIdx%n];
                }
            }
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {1,2,3,4,5,6,7},
        {-1,-100,3,99},
        {1},
        {1,2,3,4,5,6},
        {-1}
    };

    vector<int> k 
    { 
        3,
        2,
        0,
        4,
        2
    };

    vector<vector<int>> output 
    { 
        {5,6,7,1,2,3,4},
        {3,99,-1,-100},
        {1},
        {3,4,5,6,1,2},
        {-1}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        solution.rotate(nums[i], k[i]);

        for(int j=0; j<nums[i].size(); j++)
        {
            CustomAssert::run<int>(output[i][j], nums[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Theare are two approaches.

In fisrt approach, the trick is to reverse the array. Then re-reverse first k elements and the rest so that they come back to their rotated position. This trick is not very intutitive and usually does not come to mind if not known before.

In the second approach, we are roating one by one values. The only constraint is roatation can create a cycle when gcd(k,n) > 1. Therefore, we are taking an offset and incrementing it when a cycle is detected (i.e. offset == prevIdx case).
*/