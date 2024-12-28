#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"
#include <unordered_map>

using namespace std;

class Solution 
{
    public:
        string minWindow(string s, string t) 
        {
            int m=s.size(), n=t.size(), start=0, windowLen=INT_MAX, remaining=n, optimumStart=m;
            unordered_map<char,int> countS, countT;

            for(char& c : t)
            {
                countT[c]++;
            }

            for(int i=0; i<m; i++)
            {
                countS[s[i]]++;                
                if(countS[s[i]]<=countT[s[i]])
                {
                    remaining--;
                }

                while(remaining==0 && start<=i && countS[s[start]]>countT[s[start]])
                {
                    countS[s[start]]--;
                    start++;
                }

                if(remaining==0 && windowLen>i-start+1)
                {
                    windowLen=i-start+1;
                    optimumStart=start;
                }
            }
            
            return s.substr(optimumStart,windowLen);
        }
};

int main()
{
    vector<pair<string, string>> inputs 
    { 
        {"ADOBECODEBANC", "ABC"},
        {"a", "a"},
        {"a", "aa"},
    };

    vector<string> outputs 
    { 
        "BANC",
        "a",
        ""
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        string result = solution.minWindow(inputs[i].first, inputs[i].second);

        CustomAssert::run<string>(outputs[i], result, "Output mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The trick here is the count of remaining chars.

When remaining becomes 0 then we continue to expand or shrink it by keeping remaining=0.

After every iterations if windowlength is smaller we only then update: (1) string start index (2) new windowlength. 
These two are sufficient to make the substring.
*/