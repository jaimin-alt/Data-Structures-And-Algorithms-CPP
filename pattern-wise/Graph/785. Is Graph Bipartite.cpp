#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ans = true;
    void Bipertite(vector<vector<int>>& graph,int n, vector<bool>&visited,int node,int color,vector<int>&colors)
    {
        visited[node] =1;

        // apply dfs
        colors[node] = color;
        int neighbour_color = 1-color;



        for(int i = 0 ;i<graph[node].size();i++)
        {
            int neigh  = graph[node][i];

            if(visited[neigh]==false)
            {
                Bipertite(graph,n,visited,neigh,neighbour_color,colors);
            }
            else{
                if(colors[neigh]==color)
                {
                    ans = false;
                    return;
                }
            }
        }
        return;


    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool>visited(n,0);
        vector<int>colors(n,-1);

        for(int i = 0 ;i<n;i++)
        {
            
                if(visited[i]==0)
                {
                    Bipertite(graph,n,visited,i,0,colors);
                }
            
        }

        return ans;
    }
};