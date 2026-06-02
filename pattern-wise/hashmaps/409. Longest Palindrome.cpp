#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>f;

        for(char c:s)
        {
            f[c]++;
        }
        int ans = 0 ;
        bool odd = false;

        for(auto i:f)
        {
            int val = i.second;
            if(val%2==0)
            {
                ans+=val;

            }
            else{
                ans+=val-1;
                odd=true;
            }
    
        }

        if(odd)
        {
            return ans+1;
        }
        return ans;
    }
};