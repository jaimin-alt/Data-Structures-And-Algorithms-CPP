

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int high,low= 0 ;
        int ans = INT_MIN;
        int no_of_zeros = 0 ;

        for(high=0;high<n;high++)
        {
            if(nums[high]==0)
            {
                no_of_zeros++;
            }

            while(no_of_zeros>k)
            {
                if(nums[low]==0)
                {
                    no_of_zeros--;

                }
                low++;
            }

            ans=max(ans,high-low+1);


        }
        return ans;
        
    }
};