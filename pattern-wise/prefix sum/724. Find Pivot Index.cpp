

#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot=-1;

        int n=nums.size();

        int i=0;
        int total_sum=0;
        int j;
         for(j=0;j<n;j++)
         {
             total_sum+=nums[j];
         }
        int temp_sum = 0;

        int prefix_sum = 0 ;
        while(i<n)
        {
            
            
            
            if(i!=0) prefix_sum+=nums[i-1];

            temp_sum=prefix_sum+nums[i];

            if(prefix_sum==(total_sum-temp_sum))
            {
                pivot = i;
                return pivot;
            }
            i++;

        }

        return pivot;
    }
};