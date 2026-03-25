
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
         vector<vector<int>>prefix(n,vector<int>(m));
         
         vector<vector<int>>suffix(n,vector<int>(m));

         int pref = 1;
         int suff = 1;

         for(int i = 0 ;i<n;i++)
         {
            for(int j = 0 ;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    prefix[i][j] = 1;
                    pref =(( pref%12345 )*(grid[i][j]%12345)%12345) ; 

                }
                else{
                    prefix[i][j] = pref;
                    pref =(( pref%12345 )*(grid[i][j]%12345)%12345) ; 
                }
                
            }
         }

         
         for(int i = n-1;i>=0;i--)
         {
            for(int j = m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    suffix[i][j] = 1;
                    suff =(( suff%12345 )*(grid[i][j]%12345)%12345) ; 

                }
                else{
                    suffix[i][j] = suff;
                    suff =(( suff%12345 )*(grid[i][j]%12345)%12345) ; 
                }
                
            }



            
         }


                  vector<vector<int>>ans(n,vector<int>(m));

                  for(int i=0 ;i<n;i++)
                  {
                    for(int j = 0 ;j<m;j++)
                    {
                ans[i][j] = ((prefix[i][j]%12345 )* (suffix[i][j]%12345) % 12345) ; 
                    }
                  }

                  return ans;

    }
};