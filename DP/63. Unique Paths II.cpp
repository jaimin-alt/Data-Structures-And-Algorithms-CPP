 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPath(vector<vector<int>>&grid,int & row,int & col,vector<vector<int>>&dp,int i,int j)
    {
        if(i>=row || j>=col) return 0;
        if(grid[i][j]==1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==row-1 && j==col-1) return 1;
                          // right                         // bottom
        return dp[i][j] = findPath(grid,row,col,dp,i,j+1) + findPath(grid,row,col,dp,i+1,j);

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return findPath(obstacleGrid,row,col,dp,0,0);

    }
};