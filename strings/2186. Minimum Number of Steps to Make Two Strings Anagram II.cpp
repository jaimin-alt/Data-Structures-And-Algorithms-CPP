#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq_s(26,0);
        vector<int>freq_t(26,0);
        int s_size= s.size();
        int t_size = t.size();

        for(int i=0;i<s_size;i++)
        {
            freq_s[s[i]-97]++;

        }
        for(int i=0;i<t_size;i++)
        {
            freq_t[t[i]-97]++;
        }

        int ans = 0 ;

        for(int i=0;i<26;i++)
        {
            ans+=abs(freq_s[i]-freq_t[i]);
        }

        return ans;
    }
};