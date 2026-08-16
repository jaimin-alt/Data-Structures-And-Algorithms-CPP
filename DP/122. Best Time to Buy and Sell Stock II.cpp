// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(vector<int>&prices,int n,int k,vector<vector<int>>&dp,int i)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        // buy
        if(k==2)
        {
            int c1 = fun(prices,n,k-1,dp,i+1) - prices[i];
            int c2 = fun(prices,n,k,dp,i+1);

            return dp[i][k] = max(c1,c2);
        }
            // sell 
        
            int c1 = fun(prices,n,2,dp,i+1) + prices[i];
            int c2 = fun(prices,n,k,dp,i+1);

            return dp[i][k] = max(c1,c2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for(int i = n-1;i>=0;i--)
        {
            dp[i][2] = max(dp[i+1][1]-prices[i],dp[i+1][2]);

            dp[i][1] = max(dp[i+1][2]+prices[i],dp[i+1][1]);
        }

        return dp[0][2];
    }
};