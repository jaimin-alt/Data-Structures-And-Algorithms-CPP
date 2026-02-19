#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
     set<int>s1(nums.begin(),nums.end());
     int distinct  = s1.size();
     int ans = 0 ;

     for(int i=0;i<nums.size();i++)
     {
        set<int>s2;

        for(int j=i;j<nums.size();j++)
        {
            s2.insert(nums[j]);
            if(s2.size()==distinct)
            {
                ans++;
            }else if(s2.size()>distinct)
            {
                break;
            }
        }
     }   
     return ans;
    }
};