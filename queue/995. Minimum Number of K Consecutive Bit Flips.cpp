 #include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int no_flips = 0 ;
        int n = nums.size();
        queue<int>q;

        for(int i=0;i<n;i++)
        {   
            if(!q.empty() && q.front()<i)
            {
                q.pop();
            }

            if(nums[i]==q.size()%2)
            {
                if(i+k-1>=n) return -1;
                q.push(i+k-1);
                no_flips++;
            }
        }

        return no_flips;
    }
};