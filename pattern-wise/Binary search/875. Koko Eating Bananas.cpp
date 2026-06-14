#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long total_time(vector<int>&a,int n,int guess)
    {
        long long hour = 0;

        for(int x:a)
        {    
            hour+=x/guess;
            if(x%guess!=0)
            {
                hour++;
            }
        }

        return hour;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low=1;
        int high=INT_MIN;
        int ans = -1;


        for(int x:piles)
        {
            high = max(high,x);
        }

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(total_time(piles,n,mid)>h) 
            { // cannot eat in this speed so have to increase the speed go to right 
                low = mid+1;
            }
            else{ 
                // can eat in this speed so store the answer and go to the right for minimum answer
                ans = mid;
                high= mid-1;

            }
        }

        return ans;


    }
};