 #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string str) {

        if(str.size()==1)
        {
            return "/";
        }
        int n = str.size();
        vector<string>paths;

    for(int i=0;i<n;i++)
    {
        if(str[i]=='/')
        {
            i++;
            string temp="/";
            while(i<n && str[i]!='/')
            {
                temp+=str[i];
                i++;
            }

            if(temp=="/.")
            {
                paths.push_back(temp);
            }
            else if(temp=="/..")
            {
                paths.push_back(temp);
            }
            else if(temp=="/")
            {
                if(i<n)
                {
                    while(i<n && str[i]=='/')
                    {
                        i++;
                    }
                    i--;
                }

            }
            else{
                    paths.push_back(temp);
            }


        }
        i--;
    }

    stack<string>canonical;

    for(int i=0;i<paths.size();i++)
    {
        if(paths[i]=="/..")
        {
            if(!canonical.empty()) canonical.pop();
        }
        else if(paths[i]=="/.")
        {
            // empty chhod
        }
        else{
                canonical.push(paths[i]);
        }
    }

    if(canonical.empty())
    {
        return "/";

    }
   
        string ans;
        vector<string>another;

        while(!canonical.empty())
        {
            another.push_back(canonical.top());
            canonical.pop();
        }

        for(int i=another.size()-1;i>=0;i--)
        {
            ans+=another[i];
        }
        
        return ans;

    
    }
};