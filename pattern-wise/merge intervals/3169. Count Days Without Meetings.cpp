#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int meeting_days = 0 ;
        

        sort(meetings.begin(),meetings.end());
        int start1= meetings[0][0];
        int end1 = meetings[0][1];

        for(int i=1;i<n;i++)
        {
            int start2 = meetings[i][0];
            int end2 = meetings[i][1];

            // overlap 

            if(start2<=end1)
            {
                start1 = start1;
                end1 = max(end1,end2);
            }
            // no overlap then have to count the busy meeting days
            else{
                meeting_days+=end1-start1+1;
                start1 = start2;
                end1 = end2;
            }
        }

        // sauthi last vadi range baki hase
        meeting_days+=end1-start1+1;

        return days-meeting_days;
    }
};