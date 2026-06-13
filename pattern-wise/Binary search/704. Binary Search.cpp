#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans = -1,mid,start=0,end=n-1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(target==nums[mid]){
                ans=mid;
                return ans;
            }
            else if(target<nums[mid]) end = mid-1;
            else start = mid+1;
        }
        return ans;
    }
};