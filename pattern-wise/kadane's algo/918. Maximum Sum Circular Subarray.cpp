
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int max_subarray_sum(vector<int>nums)
    {
        int n = nums.size();
        int best_end = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++)
        {
            best_end = max(best_end+nums[i],nums[i]);
            ans = max(ans,best_end);
        }

        return ans;
    }

    int min_subarray_sum(vector<int>nums)
    {
        int n = nums.size();
        int best_end = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++)
        {
            best_end = min(best_end+nums[i],nums[i]);
            ans = min(ans,best_end);
        }

        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
       int total_sum= 0 ;

       int n = nums.size();

       for(int i=0;i<n;i++)
       {
        total_sum+=nums[i];
       }

       int max_subarray = max_subarray_sum(nums);
       int min_subarray = min_subarray_sum(nums);
       int max_circular_subarray_sum = total_sum - min_subarray;

       if(max_circular_subarray_sum==0)
       {
        return max_subarray;
       }

       return max(max_subarray,max_circular_subarray_sum);
    }
};