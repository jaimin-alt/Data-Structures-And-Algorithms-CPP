
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void RotateNinty(vector<vector<int>>&mat,int n,int m)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        // now reverse each of the row 

        for(int i=0;i<n;i++)
        {
            int start =  0;

            int end = m-1;

            while(start<=end)
            {
                swap(mat[i][start],mat[i][end]);
                start++;
                end--;
            }
        }


        
       
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size();
        int m = mat[0].size();

        bool is = true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=target[i][j])
                {
                    is=false;
                    break;
                }
            }
        }

        if(is)
        {
            return true;
        }

        // else  

        for(int i=0;i<3;i++)
        {
            RotateNinty(mat,n,m);

            bool is = true;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=target[i][j])
                {
                    is=false;
                    break;
                }
            }
        }

        if(is)
        {
            return true;
        }

        }

        return false;
    }
};