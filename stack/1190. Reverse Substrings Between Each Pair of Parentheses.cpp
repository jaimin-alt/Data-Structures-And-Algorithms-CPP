#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;

        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                string temp ; 
                while(st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();

                int m = temp.size();
                for(int j=0;j<m;j++)
                {
                    st.push(temp[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string ans;

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};