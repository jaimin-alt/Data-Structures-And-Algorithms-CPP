

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool compare(vector<int>freq_s,vector<int>freq_t)
    {

        for(int i =0;i<256;i++)
        {
            if(freq_t[i]!=0)
            {
                if(freq_t[i]>freq_s[i]) return false;
            }
        }

        return true;

    }
    string minWindow(string s, string t) {
        vector<int>freq_s(256,0);
        vector<int>freq_t(256,0);

        int i= 0 ;

        while(i<t.size())
        {
            freq_t[t[i++]]++;
        }

        int low=0,high;
        int n = s.size();
        int ans = INT_MAX;
        int start = -1;

        for(high=0;high<n;high++)
        {
            freq_s[s[high]]++;

            while(compare(freq_s,freq_t))
            {
                int len = high-low+1;
                if(len<ans)
                {
                    ans=len;
                    start = low;

                }
                freq_s[s[low]]--;
                low++;
            }
        }

        if(start==-1) return "";
        return s.substr(start,ans);
    }
};