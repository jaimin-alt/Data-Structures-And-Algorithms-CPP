#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),start=0,end=n-1,mid,ans=-1;

        while(start<=end)
        {
            mid = end+(start-end)/2;

            if(nums[mid]==target)
            {
                return mid;
            }

            else if(nums[0]<nums[mid])
            {
                if(nums[0]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    start = mid+1;
                }
            }

            else{
                if(nums[mid]<=target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return ans;
    }
};