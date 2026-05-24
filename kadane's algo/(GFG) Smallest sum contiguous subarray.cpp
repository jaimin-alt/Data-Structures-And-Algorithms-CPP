// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int n = a.size();
        int ans = a[0];
        int best_end= a[0];

        for(int i=1;i<n;i++)
        {
            int v1 = a[i];
            int v2 = a[i]+best_end;

            best_end = min(v1,v2);
            ans = min(ans,best_end);

        }

        return ans;
    }
};
