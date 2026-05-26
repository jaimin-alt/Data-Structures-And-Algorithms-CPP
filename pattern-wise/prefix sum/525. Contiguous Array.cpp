

#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int one = 0 ; 
        int zero = 0 ;
        int res= 0 ; 
        unordered_map<int,int>f;


        for(int i= 0 ; i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;

            }
            else{
                one++;
            }

            int diff = zero-one;

            if(diff==0)
            {
                res = max(res,i+1);
                continue;
            }

            if(f.find(diff)==f.end())  // hashmap ma nathi madyu 
            {
                f[diff] = i;

            }
            else{ // hashmap ma madi gayu 

                    int idx = f[diff];
                    int len = i-idx;

                    res = max(res,len);


            }
        }

        return res;
    }
};