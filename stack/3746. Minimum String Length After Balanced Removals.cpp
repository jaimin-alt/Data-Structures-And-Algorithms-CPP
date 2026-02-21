 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int i = 0 ;
        int count_a = 0 ,count_b = 0 ;

        while(i<n)
        {
            s[i++]=='a'?count_a++:count_b++;

        }

        return abs(count_a-count_b);
        
    }
};