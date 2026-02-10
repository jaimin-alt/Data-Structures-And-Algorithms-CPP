#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for(int i=n;i>=1;i--)
        {  int count = 0 ;
            for(int j=0;j<n;j++)
            {
                if(citations[j]>=i)
                {
                    count++;
                    if(count>=i)
                    {
                        return i;
                    }
                }

            }
        }
        return 0;
    }
};