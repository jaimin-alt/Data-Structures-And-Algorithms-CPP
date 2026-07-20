#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i , vector<vector<int>>& adj,vector<bool>&visited)
    {
        visited[i] = true;

        queue<int>q;
        q.push(i);

        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();

            // now find its neighbour

            for(int j = 0 ;j<adj.size();j++)
            {
                if(visited[j]==false && adj[currentNode][j]==1)
                {   
                    visited[j] = true;
                    q.push(j);
                }
            }
        }

        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0 ;
        vector<bool>visited(n,0);
        
        for(int i = 0 ;i<n;i++)
        {  // i is the current node
            if(visited[i]==false)
            {
                bfs(i,isConnected,visited);
                count++;
            }
        }

        return count;
    }
};