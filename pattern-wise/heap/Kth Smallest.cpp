
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int> maxHeap;
        
        for(int i=0;i<n;i++)
        {
            if(i<k)
            {
                maxHeap.push(arr[i]);
                continue;
            }
            
            if(arr[i]>=maxHeap.top())
            {
                continue;
            }
            
            if(arr[i]<maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        
        return maxHeap.top();
    }
};