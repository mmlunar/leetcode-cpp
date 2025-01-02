#include <iostream>
#include <vector>
#include "CustomAssert.h"
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution 
{
    private:
        int64_t countHours(vector<int>& piles, int r)
        {
            int64_t h = 0;

            for(int& p : piles)
            {
                h += p/r + (p%r != 0);
            }

            return h;
        }
    public:
        int minEatingSpeed(vector<int>& piles, int h) 
        {
            int left = 1, right =  *max_element(piles.begin(), piles.end()), minSpeed;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                int64_t current = countHours(piles, mid);

                if(current <= h)
                {
                    minSpeed = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return minSpeed;
        }
};


int main()
{
    vector<vector<int>> inputs 
    { 
        {3,6,7,11},
        {30,11,23,4,20},
        {30,11,23,4,20},
        {805306368,805306368,805306368},
        {312884470}
    };

    vector<int> h
    {
        8,
        5,
        6,
        1000000000,
        312884469
    };

    vector<int> outputs 
    { 
        4,
        30,
        23,
        3,
        2
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.minEatingSpeed(inputs[i], h[i]);
        CustomAssert::run<int>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*

No straightforward approach to find it.

Therefore, we made an additional function counthours that count hours required for
 a specific speed. Then we are using the concept of upper bound and implement it
 for achieving logarithmic complexity with respect to the max number of bananas in
 a pile.

*/