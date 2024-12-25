#include <iostream>
#include <vector>
#include <algorithm>
#include "CustomAssert.h"

using namespace std;

class Solution 
{
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            int m=3, n=9;
            vector<int> row(n), col(n), cell(n);

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(board[i][j] == '.')
                    {
                        continue;
                    }
                    int val = board[i][j] - '1';
                    int mask = 1<<val;

                    if((row[i] & mask) || (col[j] & mask) || (cell[(i/m)*m+j/m] & mask))
                    {
                        return false;
                    }

                    row[i] |= mask;
                    col[j] |= mask;
                    cell[(i/m)*m+j/m] |= mask;
                }
            }
            return true;
        }
};


int main()
{
    vector<vector<vector<char>>> boards 
    { 
        {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}},
        {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}},
        {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}}
    };

    vector<bool> output 
    { 
        true,
        false,
        false
    };

    int n = output.size();

    Solution solution;

    for(int i = 0; i<n; i++) 
    {
        bool result = solution.isValidSudoku(boards[i]);
        CustomAssert::run<bool>(result, output[i], "Value mismatch.");
    }

    cout<<"All tests passed!";

    return 0;
}

/*
We design the solution in a way such that it can be solved for any soduku size e.g. 16x16 or 25x25.

We are using bits to store occurance of a number in row, column, or cell.

For the 9x9 borad we just need 9 bits of an integer to check the entire board. 
If an already high bit comes high again then we have same value twice in a row, or column or cell. The it's invalid.

If it never happens then it's valid.
*/