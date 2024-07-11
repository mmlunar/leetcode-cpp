#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            int j = 1;

            for(int i = 1; i < n; i++)
            {
                if(nums[i] != nums[i-1])
                {
                    nums[j] = nums[i];
                    j++;
                }
            }

            return j;
        }
};

class CustomAssert
{
    public:
        static void run(int x, int y)
        {
            if(x != y)
            {
                cout<<"Expected: "<<x<<", Actual: "<<y<<endl;
                assert(x == y);
            }
        }

        static void run(int x, int y, string message)
        {
            if(x != y)
            {
                cout<<message<<" Expected: "<<x<<"Actual: "<<y<<endl;
                assert(x ==y);
            }
        }
};


int main()
{
    vector<vector<int>> input 
    { 
        {1,1,2},
        {0,0,1,1,1,2,2,3,3,4}
    };

    vector<vector<int>> output 
    { 
        {1,2},
        {0,1,2,3,4}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int k = solution.removeDuplicates(input[i]);
        CustomAssert::run(output[i].size(), k, "Array size mismatch.");

        for(int j =0; j<k; j++)
        {
            CustomAssert::run(output[i][j], input[i][j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";
}