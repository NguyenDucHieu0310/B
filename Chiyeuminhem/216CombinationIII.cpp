#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Build(vector<vector<int>>&res,vector<int>&cur,int k, int n, vector<bool>&used,int pos){
        if(cur.size()==k&&n==0) {res.push_back(cur); return;}
        if(n<0) return;
        for(int i =pos;i<=9;i++){
            if(!used[i-1]) {
                cur.push_back(i);
                used[i-1]=true;
                Build(res,cur,k,n-i,used,i+1);
                used[i-1]=false;
                cur.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<bool> used(9,false);
        vector<int>cur;
        Build(res,cur,k,n,used,1);
        return res;
    }
};


int main(){
    int k=3,n=7;
    
    Solution sol;
    vector<vector<int>> res=sol.combinationSum3(k,n);
    for(auto x:res){
        for(auto a:x) cout<<a<<" ";
        cout<<endl;
    }
}