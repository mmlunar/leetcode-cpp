#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int profit = 0;

            for(int i = 1; i< prices.size(); i++)
            {
                profit += max(0, prices[i] - prices[i-1]);
            }

            return profit;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {7,1,5,3,6,4},
        {1,2,3,4,5},
        {7,6,4,3,1},
    };

    vector<int> output 
    { 
        7,
        4,
        0
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.maxProfit(nums[i]);
        CustomAssert::run(output[i], result, "Value mismatch.");        
    }

    cout<<"All tests passed!";

    return 0;
}

/*
For this problem, one important point is:

- We do not need to wait for the price to go at peak. For example: prices = [1,2,3]. 
We can sell when price is 2 and then add addiitonal profit in the next step. That means, we just need
to keep eye on the previous value. If it's smaller than current vlaue then add it as a profit. 
Just imagine you are selling and then buying it again in case you have additional gain in the next stage.
*/