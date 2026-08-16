
// User function Template for C++

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fun(vector<int>&nums, int n, int i, int prev,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        if(prev==-1 || nums[i]>nums[prev])
        {
            // we have choices 

            int take = 1 + fun(nums, n, i+1,i,dp);
            int nottake = fun(nums , n , i+1,prev,dp);

            return  dp[i][prev+1] = max(take,nottake);
        }

        // we dont have any choices 
        int nottake = fun(nums , n , i+1,prev,dp);
        return dp[i][prev+1] = nottake;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(nums, n,0,-1,dp);
    }
};