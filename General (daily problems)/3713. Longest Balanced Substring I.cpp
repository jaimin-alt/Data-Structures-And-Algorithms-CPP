 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i=0;i<n;i++)
        {   char c = s[i];
            vector<int>v(26,0);
            for(int j=i;j<n;j++)
            {
                v[int(s[j]-97)]+=1;
                bool flag = true;
                for(int k=0;k<26;k++)
                {
                    if(v[k]!=0)
                    {
                        if(v[k]!=v[c-97])
                        {
                            flag = false;
                            break;
                            
                        }
                       
                        
                    }

                }

                if(flag==true)
                {
                    maxi = max(maxi,j-i+1);
                }

                
            }
        }

        return maxi;

    }
};