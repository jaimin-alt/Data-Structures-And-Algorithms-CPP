#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq_s(26,0);
        vector<int>freq_t(26,0);
        int i=0,j=0;
        int n = s.size();

        while(i<n)
        {
            freq_s[s[i++]-97]++;
            freq_t[t[j++]-97]++;
        }

        int ans = 0 ;

        for(int i=0;i<26;i++)
        {
            if(freq_s[i]>freq_t[i])
            {
                ans+=freq_s[i]-freq_t[i];
            }
        }

        return ans;
    }
};