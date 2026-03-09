
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int>temp(n,INT_MAX);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]==c)
                {
                    temp[i] = min(abs(i-j),temp[i]);
                }
            }
        }

        return temp;
    }
};