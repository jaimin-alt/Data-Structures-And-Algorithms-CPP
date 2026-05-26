

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0 ;
        int ans = 0 ;
        unordered_map<int,int>f;

        f[0] = 1;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem = sum % k ;

            if(sum<0 && rem!=0)
            {
                rem+=k;
            }

            auto it = f.find(rem);
            if(it!=f.end())
            {
                ans+=it->second;
            }

            f[rem]++;
        }

        return ans;
    }
};