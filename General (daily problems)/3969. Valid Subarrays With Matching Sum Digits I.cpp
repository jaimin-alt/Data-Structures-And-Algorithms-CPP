 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(long long sum,int x)
    {
        if(sum%10!=x) return false;
        while(sum)
        {
            if(sum==x) return true;
            sum/=10;
        }
        return false;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0 ;

        for(int i = 0 ;i<n;i++)
        { 
            long long currentSum = 0 ;
            for(int j=i;j<n;j++)
            {
                currentSum+=(long long)nums[j];
                
                
                if(valid(currentSum,x))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};