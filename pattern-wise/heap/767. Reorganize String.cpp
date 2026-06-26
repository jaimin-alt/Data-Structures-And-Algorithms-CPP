#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator()(pair<char,int>&a,pair<char,int>&b)
        {
            if(a.second!=b.second)
            {
                return a.second<b.second;
            }
            return a.first<b.first;
        }
    };
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> f;

        for(char c:s)
        {
            f[c]++;
        }
        
        priority_queue<
        pair<char,int>,
        vector<pair<char,int>>,
        cmp
        > maxHeap;

        for(auto & p : f)
        {
            maxHeap.push(p);
        }

        string res;
        
        while(!maxHeap.empty())
        {
            pair<char,int> p1 = maxHeap.top();
            maxHeap.pop();

            if(res.size()==0 || res[res.size()-1]!=p1.first)
            {
                res+=p1.first;
                p1.second--;
                if(p1.second>0)
                {
                    maxHeap.push(p1);
                }
            }
            else{
                // res no last char ane current max freq character same che
                // to current character to na push kari sakay nahi to adjucent characters same thai jase

                if(maxHeap.empty())
                {
                    return "";
                }

                pair<char,int>p2= maxHeap.top();
                maxHeap.pop();

                res+=p2.first;

                p2.second--;

                if(p2.second>0)
                {
                    maxHeap.push(p2);

                }
                maxHeap.push(p1);
            }

        }

        return res;

    }
};