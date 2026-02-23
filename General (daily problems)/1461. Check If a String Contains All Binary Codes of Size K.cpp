
 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        int n = s.size();
        int no_of_unique_substrings = pow(2,k);

        for(int i=0;i<=n-k;i++)
        {  string temp;

            for(int j=i;j<k+i;j++)
            {
                temp+=s[j];
            }
            st.insert(temp);
        }


        return (st.size()==no_of_unique_substrings);
        
    }
};