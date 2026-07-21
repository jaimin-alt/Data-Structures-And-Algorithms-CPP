
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>x = {-1,1,0,0};
    vector<int>y = {0,0,-1,1};
    bool valid(vector<vector<char>>& board,int m,int n,int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return false;
        }

        if(board[i][j]=='O')
        {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& board,int m,int n,int i,int j)
    {
        board[i][j] = '#';

        // now do for all four direction (neighbours)

        for(int k = 0 ; k<4;k++)
        {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(board,m,n,row,col))
            {
                dfs(board,m,n,row,col);
            }
        }

        return;
    }
    void solve(vector<vector<char>>& board) {
        int m  = board.size();
        int n  = board[0].size();

        // for the first row

        for(int j = 0 ;j<n;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board,m,n,0,j);
            }
        }

        // for last row 

         for(int j = 0 ;j<n;j++)
        {
            if(board[m-1][j]=='O')
            {
                dfs(board,m,n,m-1,j);
                
            }
        }

        // for first column 

         for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,m,n,i,0);
            }
        }

        // for last column 

         for(int i= 0 ;i<m;i++)
        {
            if(board[i][n-1]=='O')
            {
                dfs(board,m,n,i,n-1);
            }
        }


        //  now change the "#" to "O" and "O" to "X"

        for(int i= 0 ;i<m;i++)
        {
            for(int j = 0 ;j<n;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j] ='O';
                }
                else{
                    board[i][j] ='X';
                }
            }
        }

        return;
    }
};