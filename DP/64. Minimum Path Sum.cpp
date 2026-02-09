 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        int findMinPathSum(int&row,int&col,vector<vector<int>>&dp,int i,int j,vector<vector<int>>&grid)
        {
            if(i>=row || j>=col) return INT_MAX;
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            if(i==row-1 && j==col-1)
            {
                return grid[i][j];
            }

                return dp[i][j] = grid[i][j] + min( // right
                findMinPathSum(row,col,dp,i,j+1,grid) , 
                //bottom 
                findMinPathSum(row,col,dp,i+1,j,grid) 
                );

        }
        

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        int start_i = 0;
        int start_j = 0 ;

        return findMinPathSum(row,col,dp,start_i,start_j,grid);


    }
};