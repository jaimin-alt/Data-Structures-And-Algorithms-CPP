// User function Template for C++

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int>x = {-1,1,0,0};
    vector<int>y = {0,0,-1,1};

    bool valid(vector<vector<char>>&grid, 
            vector<vector<bool>>&visited,
            int m ,int n ,int i , int j)
        {
            if(i<0 || i>=m || j<0 || j>=n) // out of matrix 
                {
                    return false;
                }

            if(visited[i][j]==1) // visited chhe
                {
                    return false;
                }

            if(grid[i][j]=='0') // water chhe 
                {
                    return false;
                }
            
            return true;

    }

    void dfs(vector<vector<char>>&grid, 
            vector<vector<bool>>&visited,
            int m , int n , int i , int j)
    {
        visited[i][j] = 1;

        for(int k = 0 ;k<4;k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(grid , visited , m , n,row,col))
            {
                dfs(grid,visited,m,n,row,col);
            }
        }

        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        int count = 0 ;


        for(int i= 0 ; i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(grid,visited,m,n,i,j);
                    count++;
                }
            }
        }

        return count ; 
    }
};