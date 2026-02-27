#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>count;

        int n = cpdomains.size();
        for(int i=0;i<n;i++)
        {
            string temp = cpdomains[i];
            int siz = temp.size();
            int j = 0 ;
            string num;

            while(j<siz && temp[j]!=' ')
            {
                num+=temp[j++];

            }

            int number= stoi(num);
            j++;
            int k = j;
            int count_dot =  0;
            int dot_1=-1,dot_2=-1;
            string domain;
            while(k<siz)
            {   if(temp[k]=='.')
            {
                count_dot++;
                if(dot_1==-1)
                {
                    dot_1 = k;

                }
                else{
                    dot_2=k;
                }
            }
                domain+=temp[k++];

            }

            count[domain]+=number;

            if(count_dot==1)
            {
             int k = dot_1+1;
             string temp1;

             while(k<siz)
             {
                temp1+=temp[k++];
             }

             count[temp1]+=number;

            }
            if(count_dot==2)
            {

                int k = dot_1+1;
             string temp1;

             while(k<siz)
             {
                temp1+=temp[k++];
             }

             count[temp1]+=number;

             k = dot_2+1;
             string temp2;

             while(k<siz)
             {
                temp2+=temp[k++];
             }

             count[temp2]+=number;


            }

        }
       
       vector<string>ans;

       for(const auto & [domain,number] : count)
       {
        string temp;
        temp+=to_string(number);
        temp+=' ';
        temp+=domain;
        ans.push_back(temp);
       }

       return ans;

    }
};