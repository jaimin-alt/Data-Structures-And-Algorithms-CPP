

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int high = 0 ;
        int low =0;
        int ans= 0 ;
        int prod = 1;


        for(high=0;high<n;high++)
        {
            // include high
            prod*=nums[high];

            while(prod>=k && low<=high)
            {
                prod/=nums[low];
                low++;
            }

            ans+=high-low+1;
        }

        return ans;
    }
};