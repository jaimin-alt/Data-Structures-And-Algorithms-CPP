#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<string> printVertically(string s) {
        int n = s.size();
     

        int words = 0 ;
        int largest_word = 0;
        int i= 0 ;

        while(i<n)
        {   int siz = 0 ;

            while(i<n && s[i]!=' ')
            {
                siz++;
                i++;
            }
            words++;
            largest_word = max(largest_word,siz);
            i++;
        }

        int row = largest_word;
        int col = words;

        vector<vector<char>>mat(row,vector<char>(col));
     int k = 0 ;

        for(int j=0;j<col;j++)
        {
            for(int i=0;i<row;i++)
            {
                if(k>=n ||  s[k]==' ')
                {
                    mat[i][j]=' ';

                }
                else{
                    mat[i][j] = s[k++];
                }
            }
            k++;
        }

            vector<string>ans;
       
        for(int i=0;i<row;i++)
        {  string temp;
            for(int j=0;j<col;j++)
            {
                temp+=mat[i][j];
            }

            ans.push_back(temp);
        }

        //  remove the trailing space;

        for(int i=0;i<ans.size();i++)
        {

             int n = ans[i].size();
             int j=n-1;

             while(ans[i][j]==' ')
             {
                j--;
             }
            if(j!=n-1)
            {
                
             ans[i].erase(j+1);
            }

        }

        return ans;

    
    }
};