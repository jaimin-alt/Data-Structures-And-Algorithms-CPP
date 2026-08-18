#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fun(vector<int>&a,int i,int n,int k,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0;
        }

        if(k==0)
        {
            return 0;
        }

        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }

        if(k%2==0)
        {
            // buy 
            int c1 = fun(a,i+1,n,k-1,dp) - a[i];
            int c2 = fun(a,i+1,n,k,dp) ;

            return dp[i][k] = max(c1,c2);
        }

        // sell

        int c1 = fun(a,i+1,n,k-1,dp) + a[i];
        int c2 = fun(a,i+1,n,k,dp) ;

        return dp[i][k] = max(c1,c2);
        
    }
    int maxProfit(vector<int>& prices) {
        int k = 4;
        int n = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j = 1;j<=k;j++)
            {
                if(j%2==0)
                {
                    // buy

                    dp[i][j] = max(dp[i+1][j-1]-prices[i],dp[i+1][j]);

                }
                else{
                    //sell
                    dp[i][j] = max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
                }
            }
        }
        return dp[0][4];
    }
};