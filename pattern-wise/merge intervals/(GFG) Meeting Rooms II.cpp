#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        int i=0,j=0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int room = 0 ;
        int ans = 0 ;
        
        while(i<n && j<n)
        {
            if(start[i]<end[j])
            {
                room++;
                ans = max(ans,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        
        return ans;
        
    }
};
