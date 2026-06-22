 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maxDistance(string moves) {
       int R=0,L=0,U=0,D=0,underScore = 0 ;

        for(char c:moves)
        {
            if(c=='R')
            {
                R++;
            }
            else if(c=='L')
            {
                L++;
                
            }
            else if(c=='U')
            {
                U++;
                
            }
            else if(c=='D')
            {
                D++;
            }
            else{
                underScore++;
            }
        }

        return (abs(R-L)+abs(U-D)+underScore);
    }
};