 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int n = t.size();
        int i =0;
        int count1=0,count0=0;

        while(i<n)
            {
                if(t[i]=='0')
                {
                    count0++;
                }
                else{
                    count1++;
                }
                i++;
            }

        i = 0 ;
        string ans;

        while(i<n)
            {
                if(s[i]=='0')
                {
                    if(count1>0)
                    {
                        ans+='1'; 
                        count1--;
                    }
                    else{
                        ans+='0';
                        count0;
                    }
                    
                    
                }
                else{

                    if(count0>0)
                    {
                        ans+='1';
                        count0--;
                    }
                    else{
                        ans+='0';
                        count1--;
                    }
                    
                }
                i++;
            }

        return ans;

        
    }
};