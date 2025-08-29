#include<bits/stdc++.h>
using namespace std;
int cont=0;
void countSolution(vector<int>&nums, int pos, int sum){
    if(pos==nums.size()){
        if(sum==0) cont++;
        return;
    }
    for(int i=1;i<=sum/nums[pos];i++){
        countSolution(nums,pos+1,sum-i*nums[pos]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,sum;
    cin>>n>>sum;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    countSolution(nums,0,sum);
    cout<<cont;

}
