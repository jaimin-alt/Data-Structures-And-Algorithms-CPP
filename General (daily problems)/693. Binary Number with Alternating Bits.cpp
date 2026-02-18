 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string conver_binary(int n)
    {  string ans;

    if(n==0)
    {
        return "0";
    }

        while(n)
        {
            int rem = n%2;
            ans+=to_string(rem);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool hasAlternatingBits(int n) {
        string ans = conver_binary(n);

        int s = ans.size();

        for(int i=0;i<s-1;i++)
        {
            if(ans[i]==ans[i+1]) return false;
        }

        return true;
    }
};