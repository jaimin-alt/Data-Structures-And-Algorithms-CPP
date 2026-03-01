#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int size= n.size();
        int ans = 0 ;

        for(int i=0;i<size;i++)
        {  
            ans = max(ans,n[i]-'0');

        }

        return ans;
    }
};