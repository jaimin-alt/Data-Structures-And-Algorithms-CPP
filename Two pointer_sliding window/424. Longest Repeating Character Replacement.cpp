

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int find_max(vector<int>f)
    {
        int maxi = 0;

        for(int i=0;i<256;i++)
        {
            maxi = max(maxi,f[i]);
        }

        return maxi;

    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int high,low= 0 ;
        vector<int>f(256,0);
        int ans = INT_MIN;

        for(high=0;high<n;high++)
        {
            f[s[high]]++;

            int len = high-low+1;
            int maxi_freq= find_max(f);
            int to_be_replaced = len-maxi_freq;

            while(to_be_replaced>k)
            {
                f[s[low]]--;
                low++;
                len = high-low+1;
                maxi_freq = find_max(f);
                to_be_replaced = len-maxi_freq;

            }
            ans = max(ans,high-low+1);
        }

        return ans;
    }
};