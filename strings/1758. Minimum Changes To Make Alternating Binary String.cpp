#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
       
        int temp1=0;
        int temp2=0;
        int n = s.size();
        if(n==1) return 0;
        if(n==2)
        {
            return (s[0]=='0'&&s[1]=='1') || (s[0]=='1'&&s[1]=='0')?0:1;
        }

        // compare with the final string starting with 1;

        for(int i=0;i<n;i++)
        {   
            // 1
            if(i%2==0)
            {
                if(s[i]=='0')
                {
                    temp1++;
                
                }

            }
            // 0
            else{
                if(s[i]=='1')
                {
                    temp1++;
                }
            }
        }


        // compare with the final string starting with 0;

        for(int i=0;i<n;i++)
        {   
            // 0
            if(i%2==0)
            {
                if(s[i]=='1')
                {
                    temp2++;
                
                }

            }
            // 1
            else{
                if(s[i]=='0')
                {
                    temp2++;
                }
            }
        }
     return min(temp1,temp2);

    }
};