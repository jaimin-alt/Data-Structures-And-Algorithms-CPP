#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>magazine_freq(26,0);
        int n = magazine.size();

        for(int i =0;i<n;i++)
        {
            magazine_freq[magazine[i]-'a']++;
        }

        n = ransomNote.size();
        for(int i= 0 ;i<n;i++)
        {
            if(magazine_freq[ransomNote[i]-'a']<=0)
            {
                return false;
            }
            magazine_freq[ransomNote[i]-'a']--;
        }

        return true;
    }
};