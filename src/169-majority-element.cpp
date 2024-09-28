#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            int result, count = 0;

            for(int i =0; i< nums.size(); i++)
            {
                if(count == 0)
                {
                    result = nums[i];
                }

                count += nums[i] == result ? 1 : -1;
            }

            return result;
        }
};

int main()
{
    vector<vector<int>> input 
    { 
        {3,2,3},
        {2,2,1,1,1,2,2}
    };

    vector<int> output 
    { 
        3,
        2
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int k = solution.majorityElement(input[i]);
        CustomAssert::run(output[i], k, "Test case failed.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
This problem is nothing but a simpler version of Boyer-Moore Majority Voting Algorithm.

You have votes and you need to count the majority of votes. For that you need a candiate 
variable (i.e. result) and a vote counter (i.e. count). Now, you will increment the counter if
same value a.k.a. candidate is choosen. Otherwise decrement the counter. If the counter reaches 0 that means you 
choose the wrong winner. Therefore, take the next candidate and check whether that one is winner or not. Who 
eventually survives will be the winner.

The step 2, of that algorithm is not required for this problem. Because, for this one it is ensured that
there will always be an unique winner a.k.a. majority element. Otherwise we just need to count
whether the count votes is greater than the half of the total votes or not. If not then there will be no winner.

For more details, https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
*/