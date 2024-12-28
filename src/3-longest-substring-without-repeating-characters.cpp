#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        int lengthOfLongestSubstring(string s) 
        {
            int maxLength = 0, n = s.size(), start = 0;
            unordered_map<char,int> positions;

            for(int i=0; i<n; i++)
            {
                start = max(start, positions[s[i]]);
                maxLength = max(maxLength, i - start + 1);
                positions[s[i]] = i+1;
            }

            return maxLength;
        }
};

int main()
{
    vector<string> inputs 
    { 
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "tmmzuxt",
        "dvdf"
    };

    vector<int> output 
    { 
        3,
        1,
        3,
        5,
        3
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.lengthOfLongestSubstring(inputs[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
We need to consider a sliding window to design the solution easily.

Increase the window size if a character is not previously available in the window. When a repeat character apprears update the starting point of the window.

To do that efficiently, we maintain a hashmap that maps each characer's next index position that can be used as a starting point for the window.
For example, suppose character 'a' appeasrs at position 3. Then we map it as: 'a'->4. When suppose at position 8, 'a' comes back again 
then we simply use the map and take 4 as the starting position of the window. After then we update 'a'->9 for the next time.

Eventually the max window length among all the iterations will be the output.
*/