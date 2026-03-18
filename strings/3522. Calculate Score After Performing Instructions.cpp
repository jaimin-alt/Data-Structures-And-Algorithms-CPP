#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool>visited(n,false);
        long long score = 0 ;
        int i = 0 ;
        while(i>=0 && i<n)
        {   if(visited[i])
                {
                     break;
                 }
            
            
                if(instructions[i]=="add")
                {   
                    visited[i] = true;
                    score+=(long long)values[i];
                    i+=1;
                }
                else if(instructions[i]=="jump")
                {   
                    visited[i] = true;
                    i = i+values[i];
                }
            

        
        }
            
            return score;
    }
};