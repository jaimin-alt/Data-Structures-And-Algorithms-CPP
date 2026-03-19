#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0 ;
        int n = s.size();

        int i=n-1;

        while(i>=0)
        {
            if(s[i]=='1')
            {
                long long x=n-i-1;
                ans+=x;
                n--;

            }
            i--;
        }

        return ans;
    }
};