
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int min_subarray_sum(vector<int>&nums)
    {
           int n = nums.size();
        int result  = nums[0];
        int best_end = nums[0];

        for(int i=1;i<n;i++)
        {
            best_end = max(nums[i],best_end+nums[i]);
            result = max(result,best_end);
        }

        return result;

    }

    int max_subarray_sum(vector<int>&nums)
    {
        int n = nums.size();
        int result  = nums[0];
        int best_end = nums[0];

        for(int i=1;i<n;i++)
        {
            best_end = min(nums[i],best_end+nums[i]);
            result = min(result,best_end);
        }

        return result;

    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(max_subarray_sum(nums)),abs(min_subarray_sum(nums)));
    }
};