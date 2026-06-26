#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp{ 
        // pair <int  ,  int>
            //  <element,frequency>
        bool operator()(pair<int,int>&a,pair<int,int>&b)
        {
            // minheap --> frequency
            // minimum should be on top
            // is a has lower priority than b ? 
            // if a.second < b.second  ==> then a should have higher priority -> return false
            // if a.second > b.second ==> a should have lower priority ==>return true

            if(a.second>b.second)
            {
                return true;
            }
            else if(a.second<b.second) return false;


            // if both have same frequency then also we can create minheap because here the answer can be returned in any order

            return  a.first>b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>f;

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        cmp
        >minHeap;

        for(int x:nums)
        {
            f[x]++;
        }

        for(auto & p : f)
        {
            pair<int,int> curr = p;

            if(minHeap.size()<k)
            {
                minHeap.push(curr);
                continue;
            }

            // else if curr's freq is greater than or equal to top's freq then curr should be pushed and top should be removed 

            if(curr.second>=minHeap.top().second)
            {
                minHeap.pop();
                minHeap.push(curr);
            }
            else{
                // if curr's freq is less than top's freq then curr should not be pushed
                continue;
            }

        }

        // top k elements will be in minHeap 

        vector<int>ans;
        while(!minHeap.empty())
        {
            pair<int,int>top = minHeap.top();
            minHeap.pop();
            ans.push_back(top.first);
        }

        return ans;
    }
};