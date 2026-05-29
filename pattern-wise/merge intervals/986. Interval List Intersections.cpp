#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>>ans;

        int i =0 ,j=0;

        while(i<n && j<m)
        {
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];
            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            if(s1<=s2)
            {
                // intersection is there or not 

                if(e1>=s2)
                {
                    int s = max(s1,s2);
                    int e = min(e1,e2);

                    ans.push_back({s,e});

                }

            }
            else{

                if(e2>=s1)
                {
                    int s = max(s1,s2);
                    int e = min(e1,e2);

                    ans.push_back({s,e});

                }

            }

            // update i and j 

            if(e1<=e2)
            {
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};