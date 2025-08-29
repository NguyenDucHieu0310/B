#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int i=0,j=1,n=nums.size(),sum1=0,sum2=0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        while(i<=n){
            if(i<n) sum1+=nums[i];
            if(j<n) sum2+=nums[j];
            i+=2;
            j+=2;
        }
        if(n%2==1) sum1-=min(nums[0],nums[n-1]);   
         return max(sum2,sum1);
        
    }
};
int main(){
    vector<int>nums={1,2,3,4};
    Solution sol;
    cout<<sol.rob(nums);
}