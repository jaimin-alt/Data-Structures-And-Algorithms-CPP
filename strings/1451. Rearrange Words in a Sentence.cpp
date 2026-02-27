#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string arrangeWords(string text) {
      
        vector<pair<int,string>>store;
        text[0] = char(int(text[0])+32);

        int n = text.size();
        int i=0;

        while(i<n)
        {   string word ; 

            while(i<n && text[i]!=' ')
            {
                word+=text[i];
                i++;
            }

            store.push_back({word.size(),word});
            i++;
        }

        string ans;
       i=0;

        stable_sort(store.begin(),store.end(),[](const auto&a,const auto&b)
        {
            return a.first<b.first;
        });

        store[0].second[0]=char(int(store[0].second[0]) -32);
        for(int i=0;i<store.size();i++)
        {
            ans+=store[i].second;
            ans+=' ';
        }
        ans.pop_back();
        return ans;

    }
};