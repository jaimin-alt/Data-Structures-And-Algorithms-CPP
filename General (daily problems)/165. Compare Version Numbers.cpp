#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string removeTrailing(string&s)
    {
        int n = s.size();
        if(n==1) return s;
        int i=0;
        string ans;

       while(s[i]=='0' && i<n)
       {
        i++;
       }

       if(i>=n) return "0";
       while(i<n)
       {
        ans+=s[i++];
       }
        return ans;

    }

    int compare(string s1,string s2)
    {
        int x = stoi(s1);
        int y = stoi(s2);
        if(x==y) return 0;

        return x>y?1:-1;

    }
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n=version1.size(),m=version2.size();

        while(i<n && j<m)
        {
            string s1;
            while(i<n && version1[i]!='.')
            {
                s1+=version1[i++];
            }

            string s2;
            while(j<m && version2[j]!='.')
            {
                s2+=version2[j++];
            }

            s1 = removeTrailing(s1);
            s2 = removeTrailing(s2);
            int comp =  compare(s1,s2);
            if(comp==1)
            {
             return 1;
            }
            else if(comp==-1)
            {
                return -1;
            }
            i++;
            j++;
        }

        if(i>=n && j>=m) return 0;

        if(j<m)
        {
            while(j<m)
        {
            string s2;
            while(j<m && version2[j]!='.')
            {
                s2+=version2[j++];
            }           
           s2= removeTrailing(s2);
            int comp = compare("0",s2);
            if(comp==1)
            {
             return 1;
            }
            else if(comp==-1)
            {
                return -1;
            }
            j++;
        }
        return 0;
        }

        while(i<n)
        {
             string s1;
            while(i<n && version1[i]!='.')
            {
                s1+=version1[i++];
            }           
            s1 = removeTrailing(s1);
            int comp = compare(s1,"0");
            if(comp==1)
            {
             return 1;
            }
            else if(comp==-1)
            {
                return -1;
            }
            i++;
        }

        return 0;

    }
};