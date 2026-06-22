
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct cmp{
        bool operator()(pair<string,int>&a,pair<string,int>&b)
        {   // a will have higher priority so return true
            if(a.second<b.second)
            {  // here a should get higher priority than b
            // it is asking is a lower priority than b--> no 

                return false;
            } 
            // a will not have higher priority 
            else if(a.second>b.second)
            {
                return true;
            }

            // if both have equal freq. then check word if a<b then b has higher priority 

            if(a.first<b.first)
            {
                return true;
            }
             
            // b<a means a doesnot have higher priority 

            return false;


            /*
            this whole can be written as 

            if(a.second!=b.second)
            {
                return a.second>b.second;

                // a.second = 3 , b.second = 5 
                // here a should get higher priority so this should return false
                // because it asks is a lower priority than b? 
                so here 3>5 return false which is what we needed 
            }
            it is equal so based on first 

            return a.first < b.first;


            a.first = "apple" , b.first = "banana", freq is equall 

            we want b to be on top 

            b sould get higher priority 
            it is asking is a lower priority than b? - > here it should return yes
            return a.first<b.first 
            
            */
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int>f;

        for(string s:words)
        {
            f[s]++;
        }

        priority_queue<
        pair<string,int>, // what is stored in minheap
        vector<pair<string,int>>, // internal data structure is used to store it
        cmp    // based on this comparator it should compare elements
        >minHeap;

        for(auto&p:f)
        {
            pair<string,int> curr = p;
            if(minHeap.size()<k)
            {
                minHeap.push(curr);
                continue;
            }
            pair<string,int>top = minHeap.top();

            if(curr.second<top.second) // currentni freq. top karta y ochhi che to push na karvu
            {
                continue;
            }
            else if(curr.second>top.second)
            {
                // pop the top and then push current 
                minHeap.pop();
                minHeap.push(curr);
            }
            else{
                // freq. are equal
                if(curr.first<top.first)
                { 
                    // curr is smaller than top in lexico order so yes curr should be pushed
                    minHeap.pop();
                    minHeap.push(curr);

                }
                else{
                    // push na karvu if : curr is greater than top in lexico order
                    continue;
                }
            }
        }

        vector<string>ans(k);
        int j = k-1;

        while(!minHeap.empty())
        {
            ans[j] = minHeap.top().first;
            j--;
            minHeap.pop();
        }

        return ans;
    }
};