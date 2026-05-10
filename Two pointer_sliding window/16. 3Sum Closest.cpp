

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int max_dif = INT_MAX;
        int curr_sum = 0;
        sort(nums.begin(),nums.end());   
        for(int i=0;i<n-2;i++)
        {
            int left = i+1;
            int right = n-1;
            int T = target - nums[i];

            while(left<right)
            {
                int sum = nums[left] + nums[right];

                if(abs(sum+nums[i]-target)<max_dif)
                {
                    max_dif = abs((sum+nums[i])-target);
                    curr_sum = sum+nums[i];
                }

                if(sum==T)
                {
                    return target;
                }
                else if(sum<T)
                {
                    left++;

                }
                else{
                    right--;

                }
            }
        }

        return curr_sum;
    }
};