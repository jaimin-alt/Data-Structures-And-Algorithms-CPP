// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int fun(vector<int>&nums,int i,int n,vector<int>&dp)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int rob = nums[i]+fun(nums,i+2,n,dp);
        int dontRob = fun(nums,i+1,n,dp);
        return dp[i]=max(rob,dontRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return fun(nums,0,n,dp);
    }
};