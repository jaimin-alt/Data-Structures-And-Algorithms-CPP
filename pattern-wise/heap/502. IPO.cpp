
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int>maxHeap;
        vector<vector<int>> pairs ; 
        for(int i=0;i<n;i++)
        {
            pairs.push_back({capital[i],profits[i]});
        }

        sort(pairs.begin(),pairs.end());
        int ind = 0 ;

        while(k--)
        {
            while(ind<n)
            {
                
            if(pairs[ind][0]>w)
            {
                break;
            }
            else{
                maxHeap.push(pairs[ind][1]);
                ind++;
            }
            }

            if(maxHeap.empty())
            {
                return w;
            }
            else{
                w+=maxHeap.top();
                maxHeap.pop();
            }
        }
        return w;
    }
};