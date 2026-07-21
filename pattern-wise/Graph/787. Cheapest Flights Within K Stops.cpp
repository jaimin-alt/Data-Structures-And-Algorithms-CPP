#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>ans(n,INT_MAX);
        ans[src] = 0 ; 

        for(int i = 0 ;i<=k;i++)  // relax all edges k+1 times
        {

            vector<int>temp = ans;

            // relax all edges 

            for(int j = 0  ; j<flights.size(); j++)
            {
                int s  = flights[j][0];
                int d  = flights[j][1];
                int w  = flights[j][2];

                if(temp[s]!=INT_MAX)
                {
                    if(temp[s] + w < ans[d])
                    {
                        ans[d] = temp[s] + w ;
                    }
                }
            }
        }

        if(ans[dst]==INT_MAX)
        {
             return -1;

        }

        return ans[dst];
    }
};