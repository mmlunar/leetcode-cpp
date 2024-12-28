#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int characterReplacement(string s, int k) 
        {
            vector<int> count(26);
            int left=0, n=s.size(), maxCount=0;

            for(int i=0; i<n; i++)
            {
                count[s[i]-'A']++;
                maxCount = max(maxCount, count[s[i]-'A']);
                
                if(i-left+1>maxCount+k)
                {
                    count[s[left]-'A']--;
                    left++;
                }
            }

            return n-left;
        }
};

int main()
{
    vector<string> inputs 
    { 
        "ABAB",
        "AABABBA"
    };

    vector<int> k
    {
        2,
        1
    };

    vector<int> output 
    { 
        4,
        4
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.characterReplacement(inputs[i], k[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The trick is to keep track the maxCount of the same character in a sliding window.

If maxCount+k exceeds the window size then we have to remove a char from the front of the window.

We are returning n-left as the result. 

The reason, behid that is the way we are moving the sliding window. Let's explain it with an example.

Suppose, we found a window of size 5 that satisfies the given constraints. It starts from position 2 and ends at position 6.
Now the string length is 11. That menas indices are 0, 1, 2, 3, .., 10. Now from posiiton 6 to position 10 we continue to slide
the window one step each time. This sliding has two steps: (1) We append a new character in the end of the window. (2) We remove 
the leftmost char from the begeining of the window. After, step 1, we are always checking whether i-left+1<=maxCount+k or 
not. It that is true only then we can skip step 2 and get a bigger slided window. If not we are just sliding our best 
possible window again and again.

Therefore, in the end we need to count, right-left+1 for finding the window length. Since, in the end right=n-1 i.e. the 
last index, we can simply write it: n-1-left+1 or n-left.
*/