#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canShipPackages(vector<int>&a,int n,int guess_capacity,int D)
    {
        int current_days = 1;
        int sumOfPackages = 0;

        for(int i=0;i<n;i++)
        {
            if(sumOfPackages+a[i]<=guess_capacity)
            { // means we can keep the current ship in current day 
            sumOfPackages+=a[i];
            }
            else{
                // we have to go to the next day because if we add a[i] to current package sum it is increasing then guess_capacity 
                sumOfPackages = a[i];
                current_days++;
            }
        }

        if(current_days<=D) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN; // max from array 
        int high=0 ; // sum of the array 

        for(int i=0;i<n;i++)
        {
         low = max(low,weights[i]);
         high+= weights[i];
        }

        int ans = -1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(canShipPackages(weights,n,mid,days))
            { 
                // yes : then we have to store the answer and go to the left to find the minimum answer
                ans = mid;
                high = mid-1;
            }
            else{
                // no : then we have to go to the right side
                low = mid+1;
            }
        }
        return ans;
    }
};