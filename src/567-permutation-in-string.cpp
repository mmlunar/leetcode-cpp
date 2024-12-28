#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    private:
        const int NUMCHAR = 26;
    public:
        bool checkInclusion(string s1, string s2) 
        {
            int n1 = s1.size(), n2 = s2.size(), remaining = n1;
            vector<int> count1(NUMCHAR), count2(NUMCHAR);

            for(int i=0; i<n1; i++)
            {
                count1[s1[i]-'a']++;
            }

            for(int i=0; i<n2; i++)
            {
                count2[s2[i]-'a']++;

                if(count2[s2[i]-'a'] <= count1[s2[i]-'a'])
                {
                    remaining--;
                }

                if(i>=n1)
                {
                    count2[s2[i-n1]-'a']--;

                    if(count2[s2[i-n1]-'a'] < count1[s2[i-n1]-'a'] )
                    {
                        remaining++;
                    }
                }

                if(remaining == 0)
                {
                    return true;
                }
            }

            return false;
        }
};

int main()
{
    vector<pair<string, string>> inputs 
    { 
        {"ab", "eidbaooo"},
        {"ab", "eidboaoo"},
        {"adc", "dcda"},
        {"abc", "bbbca"}
    };

    vector<bool> outputs 
    { 
        true,
        false,
        true,
        true
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.checkInclusion(inputs[i].first, inputs[i].second);

        CustomAssert::run<int>(outputs[i], result, "Output mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
The trick here is the count of remaining chars.

We are trying check a permutation. Therefore, we systematically 
keeping track the remaining chars that are not matches in the sliding with length n1.
When it becomes 0 then we can immediately return true otherwise false int he end.
*/