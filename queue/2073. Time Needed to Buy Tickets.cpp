#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int n = tickets.size();
       int time = 0;

       for(int i=0;i<k;i++)
       {
        time+=min(tickets[k],tickets[i]);
       }

       for(int i=k+1;i<n;i++)
       {
        time+=min(tickets[k]-1,tickets[i]);
       }

       time+=tickets[k];
       return time;
    }
};