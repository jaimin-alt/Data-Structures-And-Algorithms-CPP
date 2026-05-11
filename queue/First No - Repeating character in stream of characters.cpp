 #include <bits/stdc++.h>
using namespace std;

int main()
{    
    string A = "ababdc"; // ans="aab#dd"
    string B = "aabbdd"; // ans="a#b#d#"
    string C = "abcacdbd"; // ans = "aaabbbd#"
     
    vector<string>que={A,B,C};

    for(int i=0;i<que.size();i++)
    {
        int n = que[i].size();
        string x = que[i];
        string ans;
        vector<int>f(26,0);
        queue<char>q;

        for(int j=0;j<n;j++)
        {
            f[x[j]-'a']++;
            if(f[x[j]-'a']==1)
            {
                q.push(x[j]);
            }

            while(!q.empty() && f[q.front()-'a']>1)
            {
                q.pop();
            }

            if(q.empty())
            {
                ans+="#";

            }
            else{
                ans+=q.front();

            }
        }

        cout<<ans<<endl<<endl;
    }


    return 0;
}