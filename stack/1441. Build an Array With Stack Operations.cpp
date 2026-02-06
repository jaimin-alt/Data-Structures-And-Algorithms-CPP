#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int size = target.size();
        int j = 0;
        for(int i=1;i<=n;i++)
        {
            if(j==size)
            {
                break;
            }
            if(i==target[j])
            {
                ans.push_back("Push");
                j++;
            }
            else{
                int count= 0 ;
                
                while(i<=n && i!=target[j])
                {
                    ans.push_back("Push");
                    count++;
                    i++;
                }
                while(count--)
                {
                    ans.push_back("Pop");
                }
                i--;
            }
        }

        return ans;
    }
};