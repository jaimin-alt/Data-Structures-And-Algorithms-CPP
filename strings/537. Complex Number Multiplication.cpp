#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a,b,c,d;

        int i=0;
        int s = num1.size();
        while(i<s && num1[i]!='+')
        {
            i++;
        }

        
            
        a = stoi(num1.substr(0,i));
        


       
        b = stoi(num1.substr(i+1,s-i-2));

        int j=0;
        int t = num2.size();
        while(j<t && num2[j]!='+')
        {
            j++;
        }


    
        c = stoi(num2.substr(0,j));

        
        d =stoi( num2.substr(j+1,t-j-2));


        

        int real = a*c-b*d;
        int image = (a*d) + (b*c);

        string ans;
       ans+=to_string(real);
       ans+='+';
       ans+=to_string(image);
       ans+='i';
   return ans;
    }
};