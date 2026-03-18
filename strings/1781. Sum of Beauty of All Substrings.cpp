#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int beautySum(string s) {
        int n =s.size();
        int ans = 0 ;
        for(int i = 0 ;i<n;i++)
        {   vector<int>freq(26,0);
            for(int j=i;j<n;j++)
            {

                freq[s[j]-'a']++;


                // find the max and min from freq. i.e. beauty of that string

                vector<int>temp(freq.begin(),freq.end());

                sort(temp.begin(),temp.end());
                int mini,maxi;

                for(int i=0;i<26;i++)
                {
                    if(temp[i]>0)
                    {   mini = temp[i];
                        break;
                    }
                }

                for(int i=25;i>=0;i--)
                {
                    if(temp[i]>0)
                    {
                        maxi = temp[i];
                        break;
                    }
                }

                ans+=(maxi-mini);

            }
        }

        return ans;
    }
};