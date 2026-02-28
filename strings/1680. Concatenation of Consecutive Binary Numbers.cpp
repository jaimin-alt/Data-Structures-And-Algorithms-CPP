#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decimal_to_binary(int n)
    {
        if(n==1) return "1";
        if(n==2) return "10";
        string ans;

        while(n)
        {
            int rem = n%2;
            if(rem==0)
            {
                ans+='0';

            }
            else{
                ans+='1';
            }
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }


    int binary_to_decimal(string s)
    {
        int n = s.size();
        int mul=1;
        int ans = 0 ;
        int i= n-1;

        while(i>=0)
        {
            if(s[i]=='1')
            {
                ans = (ans+mul)%1000000007;
            }
            mul=(mul*2)%1000000007;
            i--;
        }

        return ans;
    }
    int concatenatedBinary(int n) {
        string temp;
        for(int i=1;i<=n;i++)
        {
            temp+=decimal_to_binary(i);
        }

        return binary_to_decimal(temp);
    }
};