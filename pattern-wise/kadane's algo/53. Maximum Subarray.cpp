
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int best_end= nums[0];

        for(int i=1;i<n;i++)
        {
            int v1 = nums[i];
            int v2 = nums[i]+best_end;

            best_end = max(v1,v2);
            ans = max(ans,best_end);

        }

        return ans;
    }
};