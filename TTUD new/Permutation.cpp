#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<vector<int>>&res, vector<int>&cur,vector<bool>&used, int n){
    if(cur.size()==n) res.push_back(cur);
    else{
        for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            cur.push_back(i);
            backtrack(res,cur,used,n);
            cur.pop_back();
            used[i]=false;
        }
        }
    }
}
int main(){
    int n=4;
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> used(n, false);
   backtrack(res,cur,used,n);
    for(int i=0;i<res.size(); i++){
        for(int j=0;j<n;j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    
}