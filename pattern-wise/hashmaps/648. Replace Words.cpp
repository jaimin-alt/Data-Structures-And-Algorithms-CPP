#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
     int n = dictionary.size();
     unordered_set<string>st;
  

     for(auto x:dictionary) // for o(1) lookup
     {
        st.insert(x);
     }

     stringstream ss(sentence);
     string word,ans;

     while(ss>>word)
     {
        int x = word.size();
        // now we foundd the word. now build the word by prefix and check wether it exist in set or not 
        bool foundInSet = false;
        for(int i=0;i<x;i++)
        {
            string temp = word.substr(0,i+1);
            if(st.count(temp))
            {
                ans+=temp;
                ans+=' ';
                foundInSet = true;
                break;
            }
        }

        if(!foundInSet)
        {
            ans+=word+' ';
        }
     }

     ans.pop_back();

     return ans;

    }
};