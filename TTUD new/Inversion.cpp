#include<bits/stdc++.h>
using namespace std;

void countInversion(vector<int>&nums, int left, int right, int&c){
    int mid=left+(right-left)/2;
    if(right-left<=1){
        if(nums[left]>nums[right]) {c++; swap(nums[left], nums[right]);}
        return;
    }
    countInversion(nums,left, mid,c);
    countInversion(nums,mid+1, right,c);
    for(int i=left; i<=mid; i++){
        for(int j= mid+1; j<=right;j++)        c+=(nums[j]<nums[i]);
    }
    sort(nums.begin()+left, nums.begin()+right+1);


}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=6; 
    int c=0;
    //cin>>n;
    vector<int> nums={3,2,4,5,6,1};
    //for(int i=0; i<n;i++) cin>>nums[i];
    countInversion(nums, 0, n-1,c);
    
    cout<<c;

}