#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0,high=n-1,ans=-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(arr[mid]<arr[mid+1]) // chadhai->direct go to right side 
            {
                low = mid+1;
            }
            else{ // dhalaan-> store current and move to the left to find the first occurence of the dhalaan 
            ans = mid;
            high = mid-1;

            }
        }

        return ans;
    }
};