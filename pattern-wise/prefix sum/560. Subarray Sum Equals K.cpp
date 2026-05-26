

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>f;
        f[0] = 1;
        int sum = 0 ;
        int ans = 0 ;
        for(int i = 0 ;i<n;i++)
        {

            sum+= nums[i];
            auto it =  f.find(sum-k);
            if(it!=f.end())
            {
                ans+=it->second;
            }
            f[sum]++;
        }

        return ans;
    }
};