
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row_ans = 0 ;
        int col_ans= 0 ;

        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;i++)
        {
            int start = 0;
            int end = col-1;

            while(start<=end)
            {
                if(grid[i][start]!=grid[i][end])
                {
                    row_ans++;
                }
                start++;
                end--;
            }
        }

        for(int j=0;j<col;j++)
        {
            int start = 0;
            int end = row-1;

            while(start<=end)
            {
                if(grid[start][j]!=grid[end][j])
                {
                    col_ans++;
                }
                start++;
                end--;
            }
        }
        return min(row_ans,col_ans);
    }
};