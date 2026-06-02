#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void combination(vector<string>&mapping,string&digits,vector<string>&ans,int ind,int size,string&current)
    {    
        if(ind>=size)
        {
            ans.push_back(current);
            return;
        }

        int num = digits[ind]-'0';
        string buttons = mapping[num];
        int x  = buttons.size();

        for(int i=0;i<x;i++)
        {
            current+=buttons[i];
            combination(mapping,digits,ans,ind+1,size,current);
            current.pop_back();
        }

    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int n = digits.size();

        vector<string>ans;
        string c= "";

        combination(mapping,digits,ans,0,n,c);

        return ans;

    }
};