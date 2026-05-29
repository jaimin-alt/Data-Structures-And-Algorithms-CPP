#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        // Code Here
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();
        
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        
        for(int i=1;i<n;i++)
        {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            
            if(e1>=s2)
            {
                return true;
            }
            s1 = s2;
            e1=e2;
        }
        
        return false;
        
        
    }
};