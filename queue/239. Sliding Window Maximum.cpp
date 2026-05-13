

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
         vector<int>ans;

         if(k==1)
         {
            for(int i=0;i<n;i++)
            {
                ans.push_back(nums[i]);

            }

            return ans;
         }
        deque<int> q;

        for(int i=0;i<k-1;i++)
        {
            if(q.empty())
            {
                q.push_back(nums[i]);
            }
            else{
                if(nums[i]<=q.back())
                {q.push_back(nums[i]);

                }
                else{
                    while(!q.empty() && q.back()<nums[i])
                    {
                        q.pop_back();
                    }

                    q.push_back(nums[i]);
                }
            }
        }

        int low = 0 ;
        for(int high=k-1;high<n;high++)
        {

            if(nums[high]<=q.back())
                {
                    q.push_back(nums[high]);

                }
                else{
                    while(!q.empty() && q.back()<nums[high])
                    {
                        q.pop_back();
                    }

                    q.push_back(nums[high]);
                }


                ans.push_back(q.front());


                if(nums[low]==q.front()) q.pop_front();
                low++;

        }
   return ans;


    }
};