#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>map1;

        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                map1[nums1[i]+nums2[j]]++;
            }
        }

        unordered_map<int,int>map2;

        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
            {
                map2[nums3[i]+nums4[j]]++;
            }
        }
        int ans = 0;

        for(auto&it:map1)
        {
            int need = (-1)*it.first;
            auto it2 = map2.find(need);

            if(it2!=map2.end())
            {
                ans+=it.second*it2->second;
            }
        }

        return ans;



        
    }
};