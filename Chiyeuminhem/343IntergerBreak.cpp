#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int integerBreak(int n, vector<int>&dp) {
        if(n<=3) return n-1;
        for(int i=4;i<=n;i++){
            int maxi=0;
            for(int j=1;j<=i/2;j++ ){
                maxi=max(maxi, dp[j]*dp[i-j]);
            }
            dp[i]=maxi;
        }
        return dp[n];
    }
};
int main(){
    int n; cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    Solution sol;
    cout<<sol.integerBreak(n,dp);
}