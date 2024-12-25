#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    private:
        string getKey(string& s)
        {
            vector<int> count(26);

            for(char& c: s)
            {
                count[c-'a']++;
            }

            string hash = "";

            for(int& n : count)
            {
                hash += to_string(n) + "#";
            }

            return hash;
        }
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<string>> wordsMap;

            for(string& s : strs)
            {
                wordsMap[getKey(s)].push_back(s);
            }

            vector<vector<string>> result;

            for(auto it = wordsMap.begin(); it != wordsMap.end(); it++)
            {
                result.push_back(it->second);
            }

            return result;
        }
};

// Function to sort both inner and outer vectors
void sortVectorOfVectors(std::vector<std::vector<std::string>>& vec) 
{
    // Sort each inner vector lexicographically
    for (auto& innerVec : vec) 
    {
        std::sort(innerVec.begin(), innerVec.end());
    }

    // Sort the outer vector based on the first element of each inner vector
    std::sort(vec.begin(), vec.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) 
    {
        return a[0] < b[0];  // Sort by the first string in each inner vector
    });
}

int main()
{
    vector<vector<string>> input 
    { 
        {"eat","tea","tan","ate","nat","bat"},
        {""},
        {"a"}
    };

    vector<vector<vector<string>>> output 
    {
        {{"bat"},{"nat","tan"},{"ate","eat","tea"}},
        {{""}},
        {{"a"}}
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        vector<vector<string>> actual = solution.groupAnagrams(input[i]);
        int actualSize = actual.size(), expectedSize = output[i].size();
        CustomAssert::run<int>(actualSize, expectedSize, "Array size mismatch.");
        sortVectorOfVectors(actual);
        sortVectorOfVectors(output[i]);

        for(int j=0; j<actualSize; j++)
        {
            int len = actual[j].size();
            CustomAssert::run<int>(len, output[i][j].size(), "Group size mismatch.");

            for(int k=0; k<len; k++)
            {
                CustomAssert::run<string>(actual[j][k], output[i][j][k], "Word mismatch.");
            }
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