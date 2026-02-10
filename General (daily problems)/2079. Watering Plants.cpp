#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int n = plants.size();
        int current_capacity = capacity;
        for(int i=0;i<n;i++)
        {  
            if(current_capacity>=plants[i])
            {
                current_capacity-=plants[i];
                steps++;
            }
            else{
                current_capacity=capacity;
                steps+=(2*i+1);
                current_capacity-=plants[i];
            }
        }
        return steps;
    }
};