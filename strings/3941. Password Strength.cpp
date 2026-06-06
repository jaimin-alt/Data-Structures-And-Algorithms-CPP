#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();

        int ans =  0 ;

        vector<bool>isPresent(256,false);

        for(char c:password)
        {
            isPresent[int(c)]=true;
        }

        for(int i=0;i<256;i++)
        {
            if(isPresent[i])
            {   // for lowercase 
                if(i>=97 && i<=122)
                {
                    ans+=1;

                } 
                // for uppercase
                else if(i>=65 && i<=90)
                {
                    ans+=2;

                }
                // for 0 to 9
                else if(i>=48 && i<=57)
                {
                    ans+=3;

                }
                // for special characters  : !@#$
                // ! = 33
                // @ = 64
                // # = 35
                // $ = 36
                


                else if(i==33 || i==35 || i==36 || i==64)
                {
                    ans+=5;

                }
            }
        }

        return ans;
    }
};