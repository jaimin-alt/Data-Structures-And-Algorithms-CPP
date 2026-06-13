#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2);

        ans[0] = -1;
        ans[1] = -1;         
         int n=nums.size(),start=0,end=n-1,mid;

         while(start<=end)
         {
            mid = start + (end-start)/2;

            if(nums[mid]==target){
                ans[0] = mid;
                end = mid-1;
                
            }
            else if(nums[mid]<target){
                start= mid+1;
            }
            else{
                end = mid-1;
            }
         }

         start = 0,end=n-1;

         while(start<=end)
         {
            mid = start + (end-start)/2;

            if(nums[mid]==target){
                ans[1] = mid;
                start = mid+1;
                
            }
            else if(nums[mid]<target){
                start= mid+1;
            }
            else{
                end = mid-1;
            }
         }

         return ans;
    }
};