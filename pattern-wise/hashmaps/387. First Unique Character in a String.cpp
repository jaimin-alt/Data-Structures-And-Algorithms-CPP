#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int ind=-1;

        vector<int> count(26,0);

        int n = s.size();

        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
        }

        int i=0;

        while(i<n)
        {
            if(count[s[i]-'a']==1)
            {
                ind = i;
                break;
            }
            i++;
        }
        return ind;
    }
};