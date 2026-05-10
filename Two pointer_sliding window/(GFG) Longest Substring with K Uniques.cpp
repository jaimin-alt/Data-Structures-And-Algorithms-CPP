
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int high,low = 0 ;
        int ans = INT_MIN;
        unordered_map<char,int>f;
        
        
        for(high=0;high<n;high++)
        {
            f[s[high]]++;
            
            while(f.size()>k)
            {
                f[s[low]]--;
                if(f[s[low]]==0)
                {
                    f.erase(s[low]);
                }
                low++;
                
            }
            
            
            if(f.size()==k)
            {
                ans=max(ans,high-low+1);
            }
        }
        if(ans==INT_MIN)
        {
            return -1;
        }
        return ans;
      
    }
};