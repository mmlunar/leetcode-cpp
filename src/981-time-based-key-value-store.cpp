#include <iostream>
#include <vector>
#include "CustomAssert.h"
#include <unordered_map>

using namespace std;

class TimeMap 
{
    private:
        unordered_map<string, vector<pair<int, string>>> timeMapData;
    public:
        TimeMap() 
        {            
        }
        
        void set(string key, string value, int timestamp) 
        {
            timeMapData[key].emplace_back(timestamp, value);
        }
        
        string get(string key, int timestamp) 
        {
            vector<pair<int, string>>& data = timeMapData[key];
            int left = 0, right = data.size() - 1;
            string value;

            while(left <= right)
            {
                int mid = left + (right - left) / 2;

                if(timestamp >= data[mid].first)
                {
                    value = data[mid].second;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            return value;
        }
};


int main()
{
    vector<string> input = {"TimeMap","set","get","get","set","get","get"};


    vector<vector<string>> values = {{},{"foo","bar","1"},{"foo","1"},{"foo","3"},{"foo","bar2","4"},{"foo","4"},{"foo","5"}};

    vector<string> output = {"", "", "bar", "bar", "", "bar2", "bar2"};
    
    TimeMap timeMap;

    int m = input.size();

    for(int i = 0; i<m; i++) 
    {
        if(input[i] == "TimeMap")
        {
            timeMap = TimeMap();
        }
        else if(input[i] == "set")
        {
            timeMap.set(values[i][0], values[i][1], stoi(values[i][2]));
        }
        else if (input[i] == "get")
        {
            string getResult = timeMap.get(values[i][0], stoi(values[i][1]));
            CustomAssert::run<string>(getResult, output[i], "Get value mismatch");
        }
    }

    cout<<"All tests passed!";

    return 0;
}

/*

The key tactics here is the data structure: unordered_map<string, vector<pair<int, string>>> timeMapData;

This data structure makes the entire process super easy. Each keay can save as many as required values based on timestamp.

Since timestamps always comes incrementally, the vector for each key is sorted. Therefore, searching values is just a binary search.

Logics of upper bound utilized here.

Make sure to use the refeence of vector so that it does not get a TLE for copying too much data for some inputs.
*/