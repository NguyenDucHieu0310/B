#include<bits/stdc++.h>
using namespace std;

int MES(vector<int>&nums){
   int n=nums.size();
   vector<int> odd(n,0);
   vector<int> even(n,0);
   if(nums[0]&1) odd[0]=nums[0];
   else even[0]=nums[0];
   long long int max=LONG_LONG_MIN;
   for(int i=1;i<n;i++){
       if(nums[i]&1) 
           odd[i] = odd[i-1] + nums[i];
       else 
           even[i] = even[i-1] + nums[i];
   }
   for(int i=0; i<n; i++){
       if(even[i] > max) max = even[i];
       if(odd[i] > max) max = odd[i];
   }
   return max;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i=0; i<n;i++)cin>>nums[i];
   int res=MES(nums);
   cout<<res;
}
