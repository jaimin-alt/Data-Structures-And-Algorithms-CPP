#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool player1 = true;
        

        int player1_score = 0,player2_score = 0;

       int n = nums.size();

       for(int i=0;i<n;i++)
       {
        if(nums[i]%2!=0)
        {
            player1 = !player1;
           
        }

        if((i+1)%6==0)
        {
            player1=!player1;
        }

        if(player1)
        {
            player1_score+=nums[i];

        }
        else{
            player2_score+=nums[i];
        }
        
       }

       return  player1_score-player2_score;
    }
};