 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        if((startPos[0]==homePos[0]) && (startPos[1]==homePos[1]))
        {
            return 0;
        }

        int n = rowCosts.size();
        int m = colCosts.size();

        int ans = 0 ;

        if(startPos[0]<=homePos[0])
        {
            // start upar che home karta
            for(int i = startPos[0]+1;i<=homePos[0];i++)
            {
                ans+=rowCosts[i];
            }
        }
        else{
            //start niche chhe home karrta

            for(int i = startPos[0]-1;i>=homePos[0];i--)
            {
                ans+=rowCosts[i];
            }
        }


        if(startPos[1]<=homePos[1])
        {
            // start left che home karta
            for(int i = startPos[1]+1;i<=homePos[1];i++)
            {
                ans+=colCosts[i];
            }
        }
        else{
            //start right chhe home karrta

            for(int i = startPos[1]-1;i>=homePos[1];i--)
            {
                ans+=colCosts[i];
            }
        }

        return ans;
    }
};