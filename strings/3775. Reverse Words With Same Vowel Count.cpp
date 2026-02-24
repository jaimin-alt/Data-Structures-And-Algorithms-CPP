#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        string ans;
        string first_word;
        int vowel_count=0;

        while(i<n && s[i]!=' ')
            {    
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    vowel_count++;
                }
                first_word+=s[i++];
            }
            if(i==n)
            {
                return s;
            }
            ans+=first_word;
            ans+=' ';
            i++;

        while(i<n){
            string word;
            int count= 0 ;

            while(i<n && s[i]!=' ')
            {   
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                {
                    count++;
                }
                word+=s[i++];    
            }

            if(vowel_count==count)
            {
                reverse(word.begin(),word.end());
            }

            ans+=word;
            ans+=' ';
            i++;
        }

        ans.pop_back();
        return ans;
    }
};