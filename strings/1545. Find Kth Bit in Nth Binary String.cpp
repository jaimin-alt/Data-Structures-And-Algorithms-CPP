#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
string inverse(string s)
{
    string temp;

    int n = s.size();
    int i=0;

    while(i<n)
    {
        s[i++]=='0'?temp+='1':temp+='0';
    }
    return temp;
}
string fun(int n,int ind)
{
    if(ind==1)
    {
        return "0";

    }

    string x = fun(n,ind-1);
    string inversed = inverse(x);
     reverse(inversed.begin(),inversed.end());

    string ans = x  + "1" + inversed;

    return ans;

}
    char findKthBit(int n, int k) {
        string s = fun(n,n);

        return s[k-1];
    }
};