#include <iostream>
#include <vector>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool isAnagram(string s, string t) 
        {
            vector<int> count(26);

            for(char& c : s)
            {
                count[c-'a']++;
            }

            for(char& c : t)
            {
                count[c-'a']--;
            }

            for(int i=0; i<26; i++)
            {
                if(count[i] != 0)
                {
                    return false;
                }
            }

            return true;
        }
};

int main()
{
    vector<string> s 
    { 
        "anagram",
        "rat"
    };

    vector<string> t 
    { 
        "nagaram",
        "car"
    };

    vector<bool> output 
    { 
        true,
        false
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.isAnagram(s[i], t[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
For this problem the key is to find an optimal way to count the characters of a string.

SInce, this problem specifically mentions lowercase char only we take a 26 int long vector and then count and match.
*/