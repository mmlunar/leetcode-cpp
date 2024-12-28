#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"
#include <deque>

using namespace std;

class Solution1 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            deque<pair<int,int>> window;
            int n = nums.size();
            vector<int> maxSW(n-k+1);

            for(int i=0; i<n; i++)
            {
                while(!window.empty() && window.back().first<nums[i])
                {
                    window.pop_back();
                }
                window.push_back({nums[i],i});

                if(window.front().second<=i-k)
                {
                    window.pop_front();
                }

                if(i-k+1>=0)
                {
                    maxSW[i-k+1] = window.front().first;
                }
            }

            return maxSW;
        }
};

class Solution2 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            deque<int> window;
            int n = nums.size();
            vector<int> maxSW(n-k+1);

            for(int i=0; i<n; i++)
            {
                while(!window.empty() && nums[window.back()]<nums[i])
                {
                    window.pop_back();
                }
                window.push_back(i);

                if(window.front()<=i-k)
                {
                    window.pop_front();
                }

                if(i-k+1>=0)
                {
                    maxSW[i-k+1] = nums[window.front()];
                }
            }

            return maxSW;
        }
};


int main()
{
    vector<vector<int>> nums 
    { 
        {1,3,-1,-3,5,3,6,7},
        {1},
        {1,3,1,2,0,5}
    };

    vector<int> k
    {
        3,
        1,
        3
    };

    vector<vector<int>> output 
    { 
        {3,3,5,5,6,7},
        {1},
        {3,3,2,5}
    };

    int n = output.size();

    Solution1 solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> result = solution.maxSlidingWindow(nums[i], k[i]);

        int m = result.size();

        CustomAssert::run<int>(m, output[i].size(), "Array size mismatch.");

        for(int j=0; j<m; j++)
        {
            CustomAssert::run<int>(output[i][j], result[j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Monotonic decreasing deque is the trick.

This deque takes at most k numbers. It makes sure only numbers that are greater 
than the current numer is in the deque. Cause smaller number of the current number 
has no impact in the maximum window value.

Two slution provided here. Solution1 is easy to interpret. Cause we need both num and the index of the num.
But, solution 2, is a bit more effecient (space wise) since index of an array can retrive the corresponding 
value in O(1) time.
*/