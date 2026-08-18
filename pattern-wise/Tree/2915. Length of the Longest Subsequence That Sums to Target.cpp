 #include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int fun(vector<int>&nums,int target,int i,int n,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return 0;
        }
        if(i>=n)
        {
            return INT_MIN;
        }

        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }

        if(nums[i]<=target)
        {
            int take =1+ fun(nums,target-nums[i],i+1,n,dp);
            int nottake = fun(nums,target,i+1,n,dp);

            return dp[i][target] = max(take,nottake);
        }

        
            int nottake = fun(nums,target,i+1,n,dp);

            return dp[i][target] = nottake;
        
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        //  recursion + memoization
        // vector<vector<int>>dp(n,vector<int>(target+1,-1));

        // int ans = fun(nums,target,0,n,dp);

        // if(ans<0)
        // {
        //     return -1;
        // }
        // return ans;

        // tabulation 

        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        for(int i = 1;i<=target;i++)
        {
            dp[n][i] = INT_MIN;
        }

        for(int i = n-1;i>=0;i--)
        {
            for(int j = 1;j<=target;j++)
            {
               if(nums[i]<=j)
               {
                int take = dp[i+1][j-nums[i]] + 1;
                int nottake = dp[i+1][j];

                dp[i][j] = max(take,nottake);
               }
               else{
                dp[i][j] = dp[i+1][j]; //nottake
               }
            }
        }

        if(dp[0][target]<=0)
        {
            return -1;
        }

        return dp[0][target];
    }
};