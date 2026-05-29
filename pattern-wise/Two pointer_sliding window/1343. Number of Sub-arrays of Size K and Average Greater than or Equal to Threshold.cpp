
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int ans = 0 ;
        int sum  = 0 ;

        for(int i=0;i<k-1;i++)
        {
            sum+=arr[i];
        }

        int high ;
        int low = 0;

        for(high=k-1;high<n;high++)
        {
            sum+=arr[high];
            int avg = sum/k;
            if(avg>=threshold)
            {
                ans++;
            }
            sum-=arr[low];
            low++;
        }
        return ans;
    }
};