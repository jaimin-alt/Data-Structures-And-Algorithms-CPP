#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    string convert_binary(int n)
    {
        string ans;
        if(n==0) return "0";
        if(n==1) return "1";

        while(n)
        {
            int rem = n%2;
            n/=2;
            ans+=to_string(rem);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    int binaryGap(int n) {

        string binary = convert_binary(n);
        int maxi = 0;

        int i;
        int size= binary.size();

        for(int i=0;i<size;i++)
        {
            if(binary[i]=='1')
            {   bool adjacent = false;
                for(int j=i+1;j<size;j++)
                {
                    if(binary[j]=='1')
                    {
                        maxi = max(maxi,j-i);
                        i=j;
                        adjacent = true;
                        break;
                    }
                }
                if(adjacent)
                {
                    i--;
                }
                else{
                    break;
                }
            }

        }

        return maxi;
        
    }
};