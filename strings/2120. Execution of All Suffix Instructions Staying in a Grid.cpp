#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int str_size = s.size();

        vector<int>ans;

        for(int i=0;i<str_size;i++)
        {
            int inst = 0 ;
            int row = startPos[0];
            int col = startPos[1];

            for(int j=i;j<str_size;j++)
            {
                // left

                if(s[j]=='L')
                {
                    col--;
                    if(col<0)
                    {
                        break;
                    }
                }

                //right 
                else if(s[j]=='R')
                {
                    col++;
                    if(col>=n)
                    {
                        break;
                    }

                }
                //up 

                else if(s[j]=='U')
                {
                    row--;
                    if(row<0)
                    {
                        break;
                    }

                }

                //down 

                else{
                    row++;
                    if(row>=n)
                    {
                        break;
                    }

                }

                inst++;
            }

            ans.push_back(inst);

        }

        return ans;

    }
};