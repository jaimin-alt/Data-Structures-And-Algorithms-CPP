#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0 ,end = n-1,mid,min = nums[0] ;

        while(start<=end)
        {
            mid = end + (start-end)/2;

            if(nums[mid]>=nums[0]) start = mid+1;
            else {
                min = nums[mid] ;
                end = mid-1;
            }
        }
        return min;
    }
};
