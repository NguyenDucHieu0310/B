#include <bits/stdc++.h>
using namespace std;
void coinChange(vector<int>& coins, int sum) {
    vector<int> dp(sum+1,sum+1);
    vector<int> ways(sum+1,0);
    int n=coins.size();
    dp[0]=0;
    ways[0]=1;
    for(int i=1;i<sum+1;i++){
        //cout<<"a"<<endl;
        for(int x:coins){
            //cout<<x<<endl;
            if (i-x>=0){
                //cout<<"b"<<endl;
                dp[i]=min(dp[i], 1+dp[i-x]);
                ways[i]+=ways[i-x];
            }
        }
        
    }
    int numberOfCash= dp[sum]==sum+1? -1:dp[sum];
    
    cout<<numberOfCash<<" "<<ways[sum]<<endl;
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
        for(int j=0; j<c; j++){
            for(int i=0; i<4;i++) coins.push_back(coins[4*j+i]*10);
        }     
        coinChange(coins,m );
    }


}