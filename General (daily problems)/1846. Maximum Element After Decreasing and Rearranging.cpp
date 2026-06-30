
 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(arr[0]>1)
        {
            arr[0] = 1;
        }

        for(int i= 1 ;i<n;i++)
        {
            int absDiff = abs(arr[i-1]-arr[i]);
            if(absDiff<=1)
            {
                continue;
            }
            else{
                arr[i] = abs(arr[i-1]+1);
            }
        }

        // find the max

        int ans = INT_MIN;

        for(int i =0;i<n;i++)
        {
            ans= max(ans,arr[i]);
        }

        return ans;
    }
};