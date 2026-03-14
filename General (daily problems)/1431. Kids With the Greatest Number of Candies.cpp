#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans(n,false);

        for(int i=0;i<n;i++)
        {
            int x = candies[i];
            x+=extraCandies;
            bool check = false;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(x<candies[j])
                    {
                        check=true;
                        break;
                    }

                }
            }
            
            if(check==false)
            {
                ans[i]=true;
            }
        }

        return ans;
    }
};