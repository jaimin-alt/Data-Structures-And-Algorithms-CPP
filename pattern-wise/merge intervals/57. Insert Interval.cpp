#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        
        // sort based on first value 

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
        {
            return a[0]<b[0];

        });

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i=1;i<n;i++)
        {
            int start2 = intervals[i][0];
            int end2= intervals[i][1];

            if(start2<=end1) // merge 
            {
                start1 = start1;
                end1 = max(end1,end2);

            }
            else{ // no merge

            ans.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        
            }
        }

        ans.push_back({start1,end1});
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>sortedIntervals;
        int i;
        for(i=0;i<n;i++)
        {
            if(intervals[i][0]>=newInterval[0])
            {
                sortedIntervals.push_back(newInterval);
                break;
            }
            sortedIntervals.push_back(intervals[i]);

        }

        if(i==n)
        {
        sortedIntervals.push_back(newInterval);
        }

        while(i<n)
        {
            sortedIntervals.push_back(intervals[i]);
            i++;
        }

        return merge(sortedIntervals);
    }
};