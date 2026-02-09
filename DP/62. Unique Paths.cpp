 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int countPaths(vector<vector<int>>&map,int i,int j,int end_i,int end_j,vector<vector<int>>&dp)
{    if(i>=end_i+1 || j>=end_j+1)
    {
     return 0;
    }
     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }
     if(i==end_i && j==end_j)
    {
        return 1;
    }
    
   
   
    return dp[i][j]=countPaths(map,i,j+1,end_i,end_j,dp)+countPaths(map,i+1,j,end_i,end_j,dp);

}
    int uniquePaths(int m, int n) {
        vector<vector<int>>map(m,vector<int>(n));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return countPaths(map,0,0,m-1,n-1,dp);
    }
};