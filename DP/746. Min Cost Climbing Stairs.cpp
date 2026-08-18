 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // space optimized

        int n = cost.size();
       int first = cost[n-1];
       int second = 0;

        for(int i = n-2;i>=0;i--)
        {
            int oneStep = cost[i] + first;
            int twoStep = cost[i] + second;
            int temp ;

            if(i==0)
            {
                int nothing = first;
                temp = min({oneStep,twoStep,nothing});
            }
            else{
                temp = min(oneStep,twoStep);
            }

            second = first;
            first = temp;
        }

        return first;
    }
};