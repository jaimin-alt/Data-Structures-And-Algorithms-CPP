#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool can_place_cows(vector<int>&a,int cows,int guess)
    {
        int n = a.size();
        
        int prev_pos = 0;
        cows--;
        if(cows==0) return true;
        
        for(int i=1;i<n;i++)
        {
            int dist = a[i]-a[prev_pos];
            
            if(dist>=guess)
            {
                prev_pos = i;
                cows--;
                if(cows==0) return true;
            }
        }
        
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high= stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(low<=high)
        {
            int mid = low + (high -low)/2;
            
            if(can_place_cows(stalls,k,mid))
            {
                ans = mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};