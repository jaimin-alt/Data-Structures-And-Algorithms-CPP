#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int i=0,j=n-1;
        int current_a=capacityA,current_b = capacityB;
        int ans = 0 ;

        while(i<=j)
        {   
            
        if(i==j)
            {
            if(current_a==current_b)
            {
                // alice karse 
                if(current_a>=plants[i])
                {
                    current_a-=plants[i];
                }
                else{
                    ans++;
                    current_a = capacityA;
                }
                break;

            }
            else{
                if(max(current_a,current_b)>=plants[i])
                {
                    current_a>current_b?current_a-=plants[i]:current_b-=plants[i];

                }
                else{
                    ans++;
                }

                break;

            }
        }

        else{
            
            if(current_a>=plants[i])
            {
                current_a-=plants[i];
            }
            else{
                current_a=capacityA;
                current_a-=plants[i];
                ans++;
            }

            if(current_b>=plants[j])
            {
                current_b-=plants[j];
            }
            else{
                current_b=capacityB;
                current_b-=plants[j];
                ans++;

            }
        }
            i++;j--;

        }
        return ans;
    }
};