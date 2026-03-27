#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat ; 

        int n = mat.size();
        int m = mat[0].size();

       for(int h = 0;h<k;h++)
       {
         for(int i=0;i<n;i++)
        {   if(i%2==0)
            {
                int x = temp[i][0];

                for(int j = 1;j<m;j++)
                {
                    temp[i][j-1] = temp[i][j];
                }
                temp[i][m-1] = x;

            }else{
                int x = temp[i][m-1];
                
                for(int j=m-1;j>0;j--)
                {
                    temp[i][j] = temp[i][j-1];
                }
                
                temp[i][0] = x;
            }
           
        }

       }
        for(int i=0;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(temp[i][j]!=mat[i][j])
                {
                    return false;

                }
            }
        }

        return true;
    }
};