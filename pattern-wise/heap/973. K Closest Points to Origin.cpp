#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

        struct cmp{ 
        // pair <int  ,  int>
            //  <index of point , distance>
            // we want closest so maxheap will be used
            // maxheap based on distance 
            // if distance is equal we can keep element which has smallest index 
            // means in distance also we can make maxheap
        bool operator()(pair<int,double>&a,pair<int,double>&b)
        {
            // is a has lower priority than b ?
            // if distance of a is less than b --> b has higher priority -->return true
            // if distance of a is greater than b --> a has higher priority -> return false

            // maxheap -> use less<int>


            if(a.second<b.second)
            {
                return true;
            }
            else if(a.second>b.second) return false;

            return a.first<b.first;
        }
    };

    double calculateDistance(int x,int y)
    {
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size(); 
        priority_queue<
        pair<int,double>,
        vector<pair<int,double>>,
        cmp
        >maxHeap;

        for(int i = 0 ;i<n;i++)
        {
            double dist = calculateDistance(points[i][0],points[i][1]);
        
            if(maxHeap.size()<k)
            {
                maxHeap.push({i,dist});
                continue;
            }

            // k closest -- > if curr dist is less or equal to top then we should include the curr dist and pop the top dist
            if(dist<=maxHeap.top().second)
            {
                maxHeap.pop();
                maxHeap.push({i,dist});

            }
            else{
                continue;
            }

        }
        vector<vector<int>>ans;

        while(!maxHeap.empty())
        {   int ind =maxHeap.top().first;
            vector<int>temp = {
            points[ind][0],
            points[ind][1]
            };

            ans.push_back(temp);
            maxHeap.pop();
        }
        return ans;
    }
};