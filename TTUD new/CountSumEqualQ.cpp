#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum,count=0;
    cin>>n>>sum;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;cin>>x;nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    int left=0, right=n-1;
    while(left<right){
        if(nums[left]+nums[right]==sum) {count++; left++;right--;}
        else if(nums[left]+nums[right]>sum) right--;
        else left++;
    }
    cout<<count;
}