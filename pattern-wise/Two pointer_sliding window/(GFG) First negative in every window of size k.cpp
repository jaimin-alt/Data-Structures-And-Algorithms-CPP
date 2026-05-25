

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        
        vector<int>ans;
        queue<int>q;
        int low=0,high;
        
        for(high=0;high<k-1;high++)
        {
            if(arr[high]<0)
            {
                q.push(arr[high]);
                
            }
        }
        
        for(high=k-1;high<n;high++)
        {
            if(arr[high]<0)
            {
                q.push(arr[high]);
            }
            
            if(q.empty())
            {
                ans.push_back(0);
                low++;
            }
            else{
                ans.push_back(q.front());
                if(arr[low]==q.front())
                {
                    q.pop();
                    
                }
                low++;
            }
        }
        return ans;
        
        
    }
};