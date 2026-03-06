#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        if(n==1)
        {
            return true;
        }
        int i=0;
        int cont_one = 0 ;
        int cont_zero = 0 ;

        while(i<n)
        {   

            if(s[i]=='1')
            {
                if(cont_zero>=1)
                {
                    return false;
                }
              
            }
            else
            {
                cont_zero=1;

            }
            i++;
        }

        return true;


        
    }
};