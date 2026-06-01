#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        int n = text.size();

        for(int i=0;i<n;i++)
        {
            freq[text[i]-'a']++;
        }

        int b = freq['b'-'a'];
        int a= freq['a'-'a'];
        int l= freq['l'-'a']/2; 
        int o= freq['o'-'a']/2; 
        n= freq['n'-'a'];

        return min({b,a,l,o,n});
    }
};