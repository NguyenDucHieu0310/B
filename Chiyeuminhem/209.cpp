#include<bits/stdc++.h>
using namespace std;
class Solution{
public: 
    int minLength(vector<int>&nums,int target){
        int left=0, right=0, sum=0;
        int minL=INT_MAX;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=target){
                minL=min(minL,right-left+1);
                sum-=nums[left];
                left++;
            }     
            right++;    
        }
        return minL==INT_MAX?0:minL;
    }

};
int main(){
    int n, target,x;
    vector<int>nums;
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    cout<<sol.minLength(nums,target);
}