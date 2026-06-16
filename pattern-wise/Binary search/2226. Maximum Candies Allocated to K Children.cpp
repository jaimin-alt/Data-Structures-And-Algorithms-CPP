#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAllocate(vector<int>&a,int n,int guess,long long k)
    {   if(guess==0) return false;
        long long count = 0 ;
        for(int i= 0 ;i<n;i++)
        {
            count+=a[i]/guess;
        }

        if(count>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 0 ;
        int high=INT_MIN;

        for(int i=0;i<n;i++)
        {
            high =max(high,candies[i]);

        }

        int ans= 0 ;

        while(low<=high)
        {
            int mid = high - (high-low)/2;
            if(canAllocate(candies,n,mid,k))
            {
                ans = mid;
                low = mid+1;

            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
};
