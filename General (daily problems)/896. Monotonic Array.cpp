#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        // increasing maate
        bool increasing = true;
        bool decreasing = true;


        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {   
                increasing = false;

                break;

            }
        }

        // decreasing

        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {   
                 decreasing = false;
                break;
               

            }
        }

        return (increasing || decreasing );


    }
};