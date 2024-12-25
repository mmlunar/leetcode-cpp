#include <iostream>
#include <vector>
#include <unordered_map>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            unordered_map<int,int> numsMap;
            unordered_map<int,vector<int>> freqMap;
            int n = nums.size();

            for(int& num : nums)
            {
                numsMap[num]++;
            }

            for(auto& pair : numsMap)
            {
                freqMap[pair.second].push_back(pair.first);
            }

            vector<int> result;

            for(int i=n, j=0; i>0 && j<k;i--)
            {
                vector<int> current = freqMap[i];
                int cSize = current.size();
                if(cSize)
                {
                    result.insert(result.end(), current.begin(), current.end());
                    j += cSize;
                }
            }

            return result;
        }
};

int main()
{
    vector<vector<int>> input 
    { 
        {1,1,1,2,2,3},
        {1}
    };

    vector<int> k
    {
        2,
        1
    };

    vector<vector<int>> output 
    {
        {1,2},
        {1}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<int> actual = solution.topKFrequent(input[i], k[i]);
        int actualSize = actual.size(), expectedSize = output[i].size();
        CustomAssert::run<int>(actualSize, expectedSize, "Array size mismatch.");

        for(int j=0; j<actualSize; j++)
        {
            CustomAssert::run<int>(actual[j], output[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Two pointer is the key.
Pointer 1: Traverse the whole array.
Pointer 2: Increemnt only when you need to update the value.

The value only needs to be updated when current number is not equals to the immediately previous number. 
Cause only then we can say that we have a new value.
*/