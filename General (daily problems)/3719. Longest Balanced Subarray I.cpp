 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
      
        
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++)
        {   int odd_count = 0 ;
        int even_count = 0 ;
          unordered_map<int,int>map;
            for(int j=i;j<n;j++)
            {   
                if(map.find(nums[j])==map.end())
                {
                    if(nums[j]%2==0)
                    {
                        map[nums[j]] = 1;
                    even_count+=1;

                    }
                    else{
                         map[nums[j]]=1;
                    odd_count+=1;

                    }
                }

                if(odd_count==even_count)
                {
                    maxi = max(maxi,j-i+1);
                }

            }
        }

        return maxi;
    }
};