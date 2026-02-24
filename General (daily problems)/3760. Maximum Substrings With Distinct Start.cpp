 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        vector<int>vocab(26,0);
            int ans = 0 ;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(vocab[s[i]-97]==0)
            {
                ans++;
                vocab[s[i]-97]++;
            }
        }
        return ans;
    }
};