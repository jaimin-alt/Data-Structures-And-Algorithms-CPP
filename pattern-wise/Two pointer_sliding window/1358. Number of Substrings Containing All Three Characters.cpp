
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int low = 0,high;
        int ans =  0 ;

        unordered_map<char,int>f;

        for(high = 0;high<n;high++)
        {
            f[s[high]]++;
            while(f.size()>=3 && low<=high)
            {
                ans+=(n-high);
                f[s[low]]--;
                if(f[s[low]]==0)
                {
                    f.erase(s[low]);
                }
                low++;
            }
        }
        return ans;
    }
};