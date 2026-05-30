 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n = s.size();

        for(char c:s)
        {
            if(st.empty())
            {
                st.push({c,1});
            }
            else {
                if(c==st.top().first)
                {
                    if(st.top().second==k-1)
                    {
                        st.pop();
                    }
                    else{
                        int count = st.top().second;
                        st.pop();
                        st.push({c,count+1});
                    }
                }
                else{
                    st.push({c,1});

                }
            }
        }

        string ans;
        if(st.empty()) return "";

        while(!st.empty())
        {
            char c = st.top().first;
            int count = st.top().second;

            st.pop();

            while(count--)
            {
                ans+=c;
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};