#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    
    
    int numSteps(string s) {
    int steps = 0 ;
    int n = s.size();
    if(n==1) return 0;

    while(s.size()!=1){
        if(s[s.size()-1]=='0')
        {
            s =  s.substr(0,s.size()-1);
        }
        else{
            int h = s.size()-1;

            while(h>=0 && s[h]!='0')
            {
                s[h]='0';
                h--;
            }

            if(h>=0)
            {
                s[h]='1';
            }
            else{
                s = '1' + s;
            }


        }

        steps++;
    }
        return steps;
    }
};