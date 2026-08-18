#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(vector<int>&coins,int amount,int i,int n,vector<vector<int>>&dp)
    {   
        if(amount==0)
        {
            return 1;
        }
        if(i>=n)
        {
            return 0;
        }

        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        if(coins[i]<=amount)
        {
            int take = fun(coins,amount-coins[i],i,n,dp);
            int nottake = fun(coins,amount,i+1,n,dp);
            return dp[i][amount] = take+nottake;
        }

        int nottake = fun(coins,amount,i+1,n,dp);
        return dp[i][amount] = nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // for recursion + memoization
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return fun(coins,amount,0,n,dp);

        // for tabulation

        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));

        for(int i = 0 ; i<=n;i++)
        {
            dp[i][0] = 1;
        }

        for(int i = n-1;i>=0;i--)
        {
            for(int amt = 1;amt<=amount;amt++)
            {
                if(coins[i]<=amt)
                {
                    int take = dp[i][amt-coins[i]];
                    int nottake = dp[i+1][amt];
                    dp[i][amt] = (long long)take + (long long)nottake;
                }
                else{
                    int nottake = dp[i+1][amt];
                    dp[i][amt] = nottake;
                }
            }
        }

        return dp[0][amount];
    }
};