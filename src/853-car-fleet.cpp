#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "CustomAssert.h"
#include <stack>

using namespace std;

// First solution
class Solution 
{
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) 
        {
            int n = position.size();
            vector<pair<int,int>> combined(n);

            for(int i=0; i<n; i++)
            {
                combined[i] = {position[i], speed[i]};
            }

            sort(combined.rbegin(), combined.rend());

            int fleet = 1;
            double prevTime = (double)(target - combined[0].first)/combined[0].second;

            for(int i=1; i<n; i++)
            {
                double currentTime = (double)(target - combined[i].first)/combined[i].second;

                if(currentTime > prevTime)
                {
                    prevTime = currentTime;
                    fleet++;
                }
            }
            
            return fleet;
        }
};

// Second solution
class Solution1 
{
        public:
            int carFleet(int target, vector<int>& position, vector<int>& speed) 
            {
                int n = position.size();
                vector<vector<int>> combined(n, vector<int>(2));

                for(int i=0; i<n; i++)
                {
                    combined[i][0] = position[i];
                    combined[i][1] = speed[i];
                }

                sort(combined.begin(), combined.end());

                stack<double> times;

                for(int i=n-1; i>=0; i--)
                {
                    double delayTime = (double)(target - combined[i][0])/combined[i][1];
                    
                    if(times.empty() || times.top() < delayTime)
                    {
                        times.push(delayTime);
                    }
                }
                return times.size();
            }
};

int main()
{
    vector<vector<int>> positions 
    { 
        {6,8},
        {3},
        {0,2,4},
        {10,8,0,5,3}
    };

    vector<vector<int>> speeds 
    { 
        {3,2},
        {3},
        {4,2,1 },
        {2,4,1,1,3}
    };

    vector<int> targets
    {
        10,
        10,
        100,
        12
    };

    vector<int> outputs 
    { 
        2,
        1,
        1,
        3
    };

    int n = outputs.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        int result = solution.carFleet(targets[i], positions[i], speeds[i]);
        CustomAssert::run<int>(outputs[i], result, "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*

The solution lies on the relation between position and required time to reach target.

Suppose two cars stay at position p1, and position p2. Now it p1 > p2 i.e. p1 is closer to the target then they will meet each 
other only if t1 >= t2 where t1 and t2 are their corresponding times to arrive target. In words, a car that is in further 
distance can touch the nearer car only when it takes shorter time to arrive. Only this is the case when we can create a feet. 
Otherwise they will be in two different fleet.

Two make it organize we first sort all cars based on their postiions. Then
(1) First solution we count thew fleets and the increment if a new fleet arrives accoridng to the prev logic.
(2) Second solution, we maintain a monotonic increasing stack of required times and then return the stack size as result.

Both cases thge space complexity is O(n) because sorting algorithm has a space complexity of O(n).


*/