#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>&arr,int n)
    {
        int start1 = arr[0][0];
        int end1 = arr[0][1];
        vector<vector<int>>ans;
        for(int i = 1;i<n;i++)
            {

                int start2 = arr[i][0];
                int end2 = arr[i][1];

                if(start2<=end1)
                {
                    start1=start1;
                    end1 = max(end1,end2);
                }
                else{
                    // touch 
                    if(start2==end1+1)
                    {
                        start1 = start1;
                        end1 = end2;  
                    }
                    else{
                    ans.push_back({start1,end1});
                    start1 = start2;
                    end1=end2;
                        
                    }
                   
                }
            }


        ans.push_back({start1,end1});
        return ans;
        
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> potAns = mergeIntervals(occupiedIntervals,n);

        if(potAns.size()==0)
        {
            return potAns;
        }

        // now remove the free intervals
        vector<vector<int>>ans;


        for (auto &it : potAns)
        {
            int l = it[0];
            int r = it[1];
        
            // no overlap
            if (r < freeStart || l > freeEnd)
            {
                ans.push_back({l, r});
                continue;
            }
        
            // left part remains
            if (l < freeStart)
                ans.push_back({l, freeStart - 1});
        
            // right part remains
            if (r > freeEnd)
                ans.push_back({freeEnd + 1, r});
        }
        
        return ans;

        
    }
};