#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    vector<int> ans;
    void dfs(int num, int n){
        for(int i=0;i<10;i++){
            int tmp=num*10+i;
            if(tmp<=n) ans.push_back(tmp);
            else break;
            dfs(tmp,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<10;i++){
            if(i<=n)  ans.push_back(i);
            else break;
            dfs(i,n);

        }    
            
        
        return ans;

    }
};
int main(){
    Solution sol;
    for(auto x:sol.lexicalOrder(123)) cout<<x<<" ";
}