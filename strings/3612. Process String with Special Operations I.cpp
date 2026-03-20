
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans;

        int i=0 ;

        while(i<n)
        {
            if(s[i]=='*')
            {
                if(ans.size()>0)
                {
                    ans.pop_back();
                }

            }
            else if (s[i]=='#')
            {
                ans+=ans;

            }
            else if(s[i]=='%')
            {
                reverse(ans.begin(),ans.end());

            }
            else{
                ans+=s[i];
            }
            i++;
        }

        return ans;
    }
};