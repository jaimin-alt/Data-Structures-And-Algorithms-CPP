#include<bits/stdc++.h>
using namespace std;


class Solution {
public: 
    bool can_place_balls(vector<int>&a,int guess,int m )
    {
        int n = a.size();
        int prev_pos = 0;
        m--;
        if(m==0) return true;
        for(int i=1;i<n;i++)
        {
            int dist = a[i]-a[prev_pos];

            if(dist>=guess)
            {
                m--;
                prev_pos = i;
                if(m==0) return true;
            }

        }

        return false;

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int ans = -1;
        int high= position[n-1]-position[0];

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(can_place_balls(position,mid,m))
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