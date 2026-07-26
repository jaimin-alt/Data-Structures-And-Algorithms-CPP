 #include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    // recursion + memoization
    bool fun(vector<int>&a,int n,int i,int sum,int currsum,vector<vector<int>>&dp)
    {
        if(currsum==sum)
        {

            return 1;
        }
        
        if(i>=n) return 0;
        
        if(dp[i][currsum]!=-1)
        {
            return dp[i][currsum];
        }
         
        if(currsum+a[i]>sum)
        {
            return dp[i][currsum] = fun(a,n,i+1,sum,currsum,dp);
        }
        
        bool take = fun(a,n,i+1,sum,currsum+a[i],dp);
        bool nottake = fun(a,n,i+1,sum,currsum,dp);
        
        
        return dp[i][currsum] = (take || nottake );
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n  = arr.size();
        
        // tabulation
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        for(int i = 0 ;i<=sum;i++)
        {
            dp[n][i] = false;
        }
        
        for(int i = 0 ; i<=n;i++)
        {
            dp[i][sum] = true;
        }
        
        for(int i = n-1 ; i>=0 ; i --)
        {
            for(int currsum = 0 ; currsum<sum;currsum++)
            {
                if(currsum+arr[i] > sum)
                {
                    dp[i][currsum] = dp[i+1][currsum];
                }
                else{
                    int take = dp[i+1][currsum+arr[i]];
                    int nottake = dp[i+1][currsum];
                    dp[i][currsum] = (take || nottake);
                    
                }
            }
        }
        
        return dp[0][0];
    }
};