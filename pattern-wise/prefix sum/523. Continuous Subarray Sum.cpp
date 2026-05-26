


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0 ;

        unordered_map<int,int>f;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
             int rem = sum%k;

            if(rem==0 && i>=1) return true;

            if(f.find(rem)==f.end())
            {
                f[rem] = i;


            }
            else{
               int len = i - f[rem];
               if(len>=2)
               {
                return true;
               }

            }      

        }

        return false;
    }
};