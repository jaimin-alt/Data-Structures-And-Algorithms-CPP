#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        

        // first of all make weighted adjacency list 

        vector<vector<pair<int,int>>> adj(n+1); // n+1 because we have label from 1 to n 

        // we will leave index 0 as it is;

        for(int i = 0 ;i<times.size();i++)
        {
            int src = times[i][0];
            int dest = times[i][1];
            int wt = times[i][2];

            adj[src].push_back({dest,wt});
        }
        // make minHeap to find the current smallest weight node
        // minHeap of pairs ==> pair<int,int> ==> < distance , node >

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > minHeap;

        // by default it will make minHeap based on first value of pair which we wanted , if first value of two pairs are same then it will chek for second value of pair

        vector<int>dist(n+1,INT_MAX); // this will store the shortest time/distance from source to all nodes

        // first of all make distance from source to source equals to 0,and also push it into minHeap 

        dist[k] = 0;
        
        minHeap.push({0,k});

        while(!minHeap.empty())
        {
            pair<int,int>p1 = minHeap.top();
            minHeap.pop();

            int d = p1.first;
            int node = p1.second;

            if(d>dist[node])
            {
                continue;

                // because this distance is previous distance and it is updated to better distance which is in dist currently
            }

           // now do relaxation for all neighbours 

           for(int j=0;j<adj[node].size();j++)
           {
                pair<int,int>p2 = adj[node][j];

                int neigh = p2.first;
                int wt = p2.second;

                if(d+wt<dist[neigh])
                {
                    //relax that node and push
                    dist[neigh] = d + wt;
                    minHeap.push({d+wt,neigh});
                }
           }

        }

        // now at last checkk if there is any INT_MAX then return -1 otherwise find maximum from dist array 

        int ans = INT_MIN;

        for(int i = 1;i<=n;i++)
        {

            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};