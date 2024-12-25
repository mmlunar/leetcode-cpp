#include <iostream>
#include <vector>
#include <string>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    private:
        char delimeter;
    public:
        Solution()
        {
            delimeter = '#';
        }
        string encode(vector<string>& strs) 
        {
            string encoded = "";
            for(string& s : strs)
            {
                int len = s.size();
                encoded += to_string(len) + string(1, delimeter) + s;
            }

            return encoded;
        }

        vector<string> decode(string s) 
        {
            int len = 0, n = s.size(), i=0;
            vector<string> decoded;

            while(i<n)
            {
                while(s[i] != delimeter)
                {
                    len = len*10 + s[i]-'0';
                    i++;
                }
                decoded.push_back(s.substr (i+1,len));
                i += len+1;
                len = 0;
            }
            
            return decoded;
        }
};


int main()
{
    vector<vector<string>> input 
    { 
        {"neet","code","love","you"},
        {"we","say",":","yes"},
    };

    int n = input.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        string encoded = solution.encode(input[i]);
        vector<string> output = solution.decode(encoded);

        CustomAssert::run<int>(input[i].size(), output.size(), "Array size mismatch");

        for(int j =0; j<output.size(); j++)
        {
            CustomAssert::run<string>(input[i][j], output[j], "Value mismatch.");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*
Algorithm depends on how we encode.

One naive approach can be use a non-ASCII char as delimitter and then split the string for decoding.

We can improve this approach by using any random char (in this solution we use '#') but before that we log the length of the current string.

As a result, at the time of decoding we can simply traverse until get that delimiter (i.e. '#'). This will give the length of the current string.

Now simple copy the chars from the encoded string based on the length we get and continue this process.
*/