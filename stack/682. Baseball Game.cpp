#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(operations[i]=="C")
            {
                st.pop();

            }
            else if(operations[i]=="D")
            {
                int x = st.top();
                st.push(x*2);

            }else if(operations[i]=="+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);

            }
            else{
                st.push(stoi(operations[i]));

            }

        }

        if(st.empty())
        {
            return 0;
        }
        int sum = 0 ;

        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};