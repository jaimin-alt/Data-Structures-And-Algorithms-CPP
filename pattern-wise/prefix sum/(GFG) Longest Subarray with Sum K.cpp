#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n  = arr.size();
        unordered_map<int,int>m;
        int ans = 0 ;
        int sum = 0 ;
        for(int i = 0 ;i<n;i++)
        {
            sum+=arr[i];
            int x = sum-k;
            
            if(x==0)
            {
                ans = max(ans,i+1);
                auto it = m.find(sum);
                if(it==m.end())
                {
                    m[sum] = i;
                }
                continue;
                
            }
            
            auto it = m.find(x);
            if(it!=m.end())
            {
                ans=max(ans,i-m[x]);
            }
            
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
         
            
        
            
        }
        
        return ans;
    }
};