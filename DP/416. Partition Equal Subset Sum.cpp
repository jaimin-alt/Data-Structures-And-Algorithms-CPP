// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSum(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind >= nums.size() || target<0) return false;
        if (dp[ind][target] != -1) return dp[ind][target];

        // Not take
        bool notTake = subsetSum(nums, ind + 1, target, dp);
        // Take
        bool take =subsetSum(nums, ind + 1, target - nums[ind], dp) ;

        return dp[ind][target] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return subsetSum(nums, 0, target, dp);
    }
};