#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;

        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
        nums1.assign(s1.begin(),s1.end());
        nums2.assign(s2.begin(),s2.end());
        int n = nums1.size();
        int m = nums2.size();
       vector<int>first;
        for(int i = 0;i<n;i++)
        {   bool present = false;
            for(int j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    present = true;
                    break;
                }
            }

            if(!present)
            {
                first.push_back(nums1[i]);
            }
        }

        vector<int>second;

        for(int i=0;i<m;i++)
        {
            bool present = false;

            for(int j=0;j<n;j++)
            {
                if(nums2[i]==nums1[j])
                {
                    present = true;
                    break;
                }
            }
            if(!present)
            {
                second.push_back(nums2[i]);
            }
        }

        ans.push_back(first);
        ans.push_back(second);

        return ans;
    }
};