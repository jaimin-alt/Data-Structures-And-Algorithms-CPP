#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int T=0,F=0;
        int answer_T = 0 ;
        int answer_F = 0 ;
        int low = 0 ;
        // for converting false into true
        for(int high=0;high<n;high++)
        {
            if(answerKey[high]=='F')
            {
                F++;
            }

            while(F>k && low<=high)
            {
                if(answerKey[low]=='F')
                {
                    F--;
                }
                low++;

            }

            answer_T = max(answer_T,high-low+1);
        }

            low=0;

         // for converting false into true
        for(int high=0;high<n;high++)
        {
            if(answerKey[high]=='T')
            {
                T++;
            }

            while(T>k && low<=high)
            {
                if(answerKey[low]=='T')
                {
                    T--;
                }
                low++;

            }

            answer_F = max(answer_F,high-low+1);
        }

        return max(answer_T,answer_F);
    }
};