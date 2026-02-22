#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        int ans = 0;

        stack<char> st;

        int i = 0;

        while (i < n)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                i++;
            }
            else
            {

                if (st.empty())
                {

                    if (i < n - 1)
                    {
                        if (s[i + 1] == ')')
                        {
                            ans += 1;
                            i += 2;
                        }
                        else
                        {
                            ans += 2;
                            i++;
                        }
                    }
                    else
                    {
                        ans += 2;
                        i++;
                    }
                }
                else
                {

                    if (i < n - 1)
                    {
                        if (s[i + 1] == '(')
                        {
                            ans += 1;
                            i += 1;
                            st.pop();
                        }
                        else
                        {
                            st.pop();
                            i += 2;
                        }
                    }
                    else
                    {
                        ans += 1;
                        i++;
                        st.pop();
                    }
                }
            }
        }
        if (st.size() == 0)
        {
            return ans;
        }
        ans += st.size() * 2;
        return ans;
    }
};