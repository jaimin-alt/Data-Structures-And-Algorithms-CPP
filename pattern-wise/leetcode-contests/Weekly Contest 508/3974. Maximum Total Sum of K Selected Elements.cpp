#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        int n  = nums.size();
        long long ans = 0 ;
        int i = 0 ;
        while(k--)
            {
                if(mul>0)
                {
                    ans+=(long long)mul*nums[i];
                    mul--;
                    i++;
                }
                else{
                    ans+=(long long)nums[i];
                    i++;
                }            
            }

        return ans;
    }
};