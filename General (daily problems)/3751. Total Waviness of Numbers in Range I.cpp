#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int waviness(string s)
    {
        int n=s.size();
        if(n<3) return 0;
        if(n==3){
            if((s[1]>s[0] && s[1]>s[2]) || (s[1]<s[0] && s[1]<s[2]))
            {
                return 1;
            }
        }

        int wav = 0 ;

        for(int i=1;i<n-1;i++)
        {
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1]))
            {
                wav++;
            }
            

        }

        return wav;
    }
    int totalWaviness(int num1, int num2) {
        int x = num1;
        int ans = 0 ;

        while(x<=num2)
        {
            string temp = to_string(x);
            ans+=waviness(temp);
            x++;
        }

        return ans;
    }
};