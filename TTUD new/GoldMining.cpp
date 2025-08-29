#include<bits/stdc++.h>
using namespace std;
int MaxGold(vector<int>&nums, int l1, int l2){
    int n=nums.size();
    if(n==0) return 0;
    vector<int> dp(n);
    int k=0;
    int maxR=0;
    while(k<l1) {dp[k]=nums[k]; if(dp[k]<maxR) maxR=dp[k];k++;}
    for(int i=0; i+l1<=n; i++){
        //cout<<i<<endl;
        for(int j=l1; j<=l2&&i+j<n;j++){
            dp[i+j]=max(dp[i+j], dp[i]+nums[i+j]);
            //cout<<"dp"<<i+j<<" "<<dp[i+j]<<endl;
            if(dp[i+j]>maxR) maxR=dp[i+j];
        }
    }
    return maxR;

    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a,b,x;
    cin>>n>>a>>b;
    vector<int> nums;
    for(int i=0; i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int res=MaxGold(nums,a,b);
    cout<<res;
}