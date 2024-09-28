#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int buy = prices[0], n = prices.size(), profit = 0;

            for(int i=1; i<n; i++)
            {
                profit = max(profit, prices[i] - buy);
                buy = min(buy, prices[i]);
            }

            return profit;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {7,1,5,3,6,4},
        {7,6,4,3,1},
    };

    vector<int> output 
    { 
        5,
        0,
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
For this problem, we have two tasks:
1) Minimize the buy price.
2) Maximize the sell price i.e. profit (since profit = sell - buy)

Since buy must be mae before sell we are maximizing the i-th profit based on the 
minimized (i-1)-th buy value.
*/