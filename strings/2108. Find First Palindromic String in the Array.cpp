#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string w : words){
            int l = 0;
            int r = w.size() - 1;
            bool isPal = true;

            while(l < r){
                if(w[l] != w[r]){
                    isPal = false;
                    break;
                }
                l++;
                r--;
            }

            if(isPal) return w;
        }

        return "";
    }
};