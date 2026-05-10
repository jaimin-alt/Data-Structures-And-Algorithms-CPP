


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int high,low = 0 ;
        int ans = INT_MIN ;
        unordered_map<int,int>f;

        for(high=0;high<n;high++)
        {
            f[fruits[high]]++;

            while(f.size()>2)
            {
                f[fruits[low]]--;
                if(f[fruits[low]]==0)
                {
                    f.erase(fruits[low]);
                }
                low++;
            }
            ans=max(ans,high-low+1);
        }

        return ans;
    }
};