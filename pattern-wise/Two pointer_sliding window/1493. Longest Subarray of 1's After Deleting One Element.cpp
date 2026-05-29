#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int low= 0 ;
        int zero = 0;
        int ans = 0 ;

        for(int high = 0;high<n;high++)
        {   if(nums[high]==0)
        {
            zero++;
        }
            while(zero>1 && low<=high)
            {
                if(nums[low]==0)
                {
                    zero--;
                }
                low++;
                
            }

            ans = max(ans,high-low+1);
        }
        return ans-1;
    }
};