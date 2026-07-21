#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>x = {-1,1,0,0};
    vector<int>y = {0,0,-1,1};

    bool valid(vector<vector<int>>& grid,vector<vector<bool>>&visited,int n , int m , int i, int j)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        {
            return false;
        }

        if(grid[i][j]==0)
        {
            return false;
        }

        if(visited[i][j]==1)
        {
            return false;
        }

        return true;

        
    }

    int bfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int n , int m , int i, int j)
    {
        int area = 1;
        visited[i][j] =1;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            int row  = p.first;
            int col = p.second;

            // look for neighbours 
            for(int k = 0 ;k<4;k++)
            {
                int neigh_row = row + x[k] ;
                int neigh_col = col + y[k] ;

                if(valid(grid,visited,n,m,neigh_row,neigh_col))
                {
                    q.push({neigh_row,neigh_col});
                    visited[neigh_row][neigh_col] = 1;
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0 ;
        vector<vector<bool>>visited(n,vector<bool>(m,0));

        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    //apply BFS with current area as 1 because we have found 1 cell in land now while doing bfs we will increase it
                    int area = bfs(grid,visited,n,m,i,j);

                    // after applyinig bfs now we have area of that land 

                    ans = max(ans,area);
                }
            }
        }

        return ans;
    }
};