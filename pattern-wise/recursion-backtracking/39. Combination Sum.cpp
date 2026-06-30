#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination(
    vector<int>&a ,
    int n ,
    int ind ,
    int sum ,
    vector<int>&diary ,
    vector<vector<int>>&ans ,
    int target)
    {
        if(sum==target)
        {
            ans.push_back(diary);
            return;
        }

        if(ind==n)
        {
            return ;
        }

        // not take

        combination(a,n,ind+1,sum,diary,ans,target);

        // take

        if(sum+a[ind]<=target)
        {
            diary.push_back(a[ind]);
            combination(a,n,ind,sum+a[ind],diary,ans,target);
            diary.pop_back();
        }

        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        int ind = 0 ;
        int sum = 0 ;
        vector<int>diary;
        vector<vector<int>>ans;
        combination(candidates,n,ind,sum,diary,ans,target);
        return ans;

    }
};