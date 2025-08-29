#include<bits/stdc++.h>
using namespace std;

int Height(vector<int>&nums, int k){
    
    int n=nums.size()-1;
    sort(nums.begin(), nums.end(),greater<int>());
    vector<int> heights=nums;
    for(int i=0; i<=n;i++) nums[i]=nums[i]-nums[i+1];
    int count =0, sum=0;
    while(count<=n&&sum<k){
        sum+=nums[count]*(++count);
        //cout<<sum<<endl;
    }
    double sodu=sum-k;
    return heights[count]+sodu/count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n+1,0);
    for(int i=1; i<=n; i++) cin>>nums[i];
    cout<<Height(nums, k);

}