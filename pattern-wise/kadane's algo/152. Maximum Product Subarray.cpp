
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_end = nums[0];
        int min_end = nums[0];
        int result = nums[0];

        for(int i=1;i<n;i++)
        {
            int v1 = nums[i];
            int v2 = min_end*nums[i];
            int v3 = max_end*nums[i];

            min_end= min(v1,min(v2,v3));
            max_end=max(v1,max(v2,v3));
            
            result = max(result,max(min_end,max_end));
        }

        return result;
    }
};