#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAllocate(vector<int>&a,int n,int guess,int stud)
    {
        int k = 1;
        int page = 0 ;
        
        for(int i=0;i<n;i++)
        {
            if(page+a[i]<=guess)
            {
                page+=a[i];
            }
            else{
                k++;
                if(k>stud) return false;
                page = a[i];
            }
        }
        
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        
        int low = INT_MIN;
        int high  = 0 ;
        
        for(int i=0;i<n;i++)
        {
            low = max(low,arr[i]);
            high+=arr[i];
        }
        
        int ans = -1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(canAllocate(arr,n,mid,k))
            {
                // we can allocate then store the answer and move to the left for minimumanswer
                ans = mid;
                high = mid-1;
                
            }
            else{
                // we cant allocate then we have to move to the right
                low = mid +1;
            }
        }
        
        return ans;   
    }
};