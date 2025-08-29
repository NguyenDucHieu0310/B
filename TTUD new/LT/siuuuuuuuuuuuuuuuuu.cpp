#include <bits/stdc++.h>
using namespace std;
void coinChange(vector<int>& coins, int sum,vector<int>&ways) {
    vector<int> dp(sum+1,sum+1);
    //vector<int> ways(sum+1,0);
    int n=coins.size();
    dp[0]=0;
    
    for(int i=1;i<sum+1;i++){
        //cout<<i<<endl;
        for(int x:coins){
            if (i-x>=0){
                if(dp[i] > 1 + dp[i-x]) {
                   // cout<<x<<"dp"<<i<<dp[i]<<endl;
                    dp[i] = 1 + dp[i-x];
                    //cout<<x<<"dp"<<i<<dp[i]<<endl;
                }
                
            }
        }
        for(int j=1; j<=i/2; j++){
            if(dp[i]==dp[j]+dp[i-j]) ways[i]+=ways[j]*ways[i-j];
        }
    }
    //for(auto x: dp) cout<<x<<" ";
    /*for(int i=1; i<=sum; i++){
        for(int j=1; j<=i/2; j++){
            if(dp[i]==dp[j]+dp[i-j]) ways[i]+=ways[j]*ways[i-j];
            //for(auto x: ways) cout<<x<<" ";
            //cout<<endl;
        }

    }*/
    int numberOfCash= dp[sum]==sum+1? -1:dp[sum];
    cout<<numberOfCash<<" "<<ways[sum]<<endl;
    //for(auto x: ways) cout<<x<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int main;
    int N,  m,c;
    cin>>N;
    for(int i=0; i< N; i++){
        cin>>m>>c;
        if(m%1000!=0){ cout<<0<<" "<<0<<endl; continue;}
        m/=1000;
        vector<int> coins={1,2,3,5};
        vector<int> ways(m+1,0);
        ways[0]=1;
        ways[1]=1;
        ways[2]=1;
        ways[3]=1;
        ways[5]=1;
        for(int j=0; j<c; j++){
            ways[coins[4*j+i]*10]=1;
            for(int i=0; i<4;i++) coins.push_back(coins[4*j+i]*10);

        }     
        coinChange(coins,m, ways );
    }
}
