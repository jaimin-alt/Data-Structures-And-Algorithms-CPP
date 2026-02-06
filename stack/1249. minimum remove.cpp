#include<bits/stdc++.h>
using namespace std;


//  T.c : o(n) , s.c : o(n) 
// 1249 : Minimum Remove to Make Valid Parentheses (medium)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    st.push(i);
                }
                else if(s[st.top()]=='(')
                {
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }

        if(st.empty())
        {
            return s;
        }

        string ans;

        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty())
            {
                if(i==st.top())
                {
                    st.pop();
                }
                else{
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
            }

        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};