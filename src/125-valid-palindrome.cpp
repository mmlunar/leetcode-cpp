#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool isPalindrome(string s) 
        {
            int i = 0, j = s.size()-1;

            while(i<j)
            {
                while(i<j && !isalnum(s[i]))
                {
                    i++;
                }

                while(i<j && !isalnum(s[j]))
                {
                    j--;
                }

                if(isalnum(s[i]) && isalnum(s[j]) && tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }

                i++;
                j--;
            }

            return true;
        }
};

int main()
{
    vector<string> s 
    { 
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };

    vector<bool> output 
    { 
        true,
        false,
        true
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.isPalindrome(s[i]);
        CustomAssert::run<int>(output[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
A standard two pointer algorithm where we need to check the chars from each pointer.

For ignoring the non alpha numeric chars we use two while loops and then check the lowcase converted result.
*/