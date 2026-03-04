 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int>col(c);
        vector<int>row(r);

        for(int i=0;i<r;i++)
        {   int ones= 0;

            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==1)
                {
                    ones++;
                }

            }

            row[i] = ones;
        }

        
        for(int j=0;j<c;j++)
        {   int ones= 0;

            for(int i=0;i<r;i++)
            {
                if(mat[i][j]==1)
                {
                    ones++;
                }

            }

            col[j] = ones;
        }
        int ans = 0 ;
for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        if(mat[i][j])
        {
            if(row[i]==1 && col[j]==1)
            {
                ans++;
            }
        }
    }
}

return ans;



    }
};