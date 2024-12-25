#include <iostream>
#include <vector>
#include <unordered_set>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            unordered_set<int> numsSet(nums.begin(), nums.end());
            int maxSeq = 0;

            for(int& n : nums)
            {
                if(numsSet.find(n-1) != numsSet.end())
                {
                    continue;
                }
                
                int seq = 0;
                while(numsSet.count(n+seq))
                {
                    seq++;
                }
                maxSeq = max(seq, maxSeq);
            }

            return maxSeq;
        }
};

int main()
{
    vector<vector<int>> nums 
    { 
        {100,4,200,1,3,2},
        {0,3,7,2,5,8,4,6,0,1}
    };

    vector<int> output 
    { 
        4,
        9
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.longestConsecutive(nums[i]);
        CustomAssert::run<int>(result, output[i], "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
It's obvious that traversing the hashset will direct you to the right answer.

But blindly traversing will make it a quardetic time algorithm. 

For making it optimal we can only traverse from the smallest number of the sequence. How we know that who is smallest in a specific sequence?
Just check the number's previous one. If that's not present only then check the sequence length.

This wil ensure that each number is checked only once and that ensures a linear time algorithm for finding the max sequence length.
*/