#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
    int m=a.length(), n=b.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=0; i<=m;i++){
        for(int j=0; j<=n;j++){
            if(i==0) dp[0][j]=0;
            else if(j==0) dp[i][0]=0;
            else {
                int cur = (a[i-1] == b[j-1]) ? 1 + dp[i - 1][j - 1] : dp[i - 1][j - 1];
                dp[i][j]=max({dp[i][j-1], dp[i-1][j], cur});
            }

        }
    }
    cout<<dp[m][n];
}