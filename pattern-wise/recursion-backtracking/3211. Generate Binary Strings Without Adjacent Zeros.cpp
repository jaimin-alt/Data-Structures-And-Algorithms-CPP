#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void generate(int i,string&current,vector<string>&ans,int n)
    {
        if(i>n)
        {
            ans.push_back(current);
            return;
        }

        if(current.size()==0)
        {
             /// add 1
            current+="1";
            generate(i+1,current,ans,n);
            current.pop_back();
            

            // add 0

            
            current+="0";
            generate(i+1,current,ans,n);
            current.pop_back();
        }
        else{
            
        if(current[current.size()-1]=='1')
        {   /// add 1
            current+="1";
            generate(i+1,current,ans,n);
            current.pop_back();
            

            // add 0

            
            current+="0";
            generate(i+1,current,ans,n);
            current.pop_back();

        }
        else{

            // we can only add 1 at the end

            current+="1";
            generate(i+1,current,ans,n);
            current.pop_back();


        }
        }

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp="";
        int i = 1 ;

        
        generate(i,temp,ans,n);

        return ans;


    }
};