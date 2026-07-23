#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(int r,int c,int n, int m,vector<vector<char>>& board )
    {
        if(r<0 || c<0 || r>=n || c>=m)
        {
            return false;
        }

        if(board[r][c]=='X') return true;
        return false;
    }
    int countBattleships(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        int ans = 0 ;
        for(int i = 0 ;i<n;i++)
        {
            for(int j= 0 ;j<m;j++)
            {
                if(board[i][j]=='X')
                {
                    ans++;

                    // now apply dfs for this in either row wise or col wise 
                    // if in that row only if it has 'X' then apply row wise 
                    // if in that col it has 'X' then apply col wise

                    // row wise 

                    if(valid(i,j+1,n,m,board))
                    {
                        for(int k = j ; k<m;k++)
                        {
                            if(board[i][k]=='X')
                            {
                                board[i][k] = '.';
                            }
                            else{
                                break;
                            }
                        }
                    }
                    else{ // colwise
                        for(int k = i ; k<n;k++)
                        {
                            if(board[k][j]=='X')
                            {
                                board[k][j] = '.';
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};