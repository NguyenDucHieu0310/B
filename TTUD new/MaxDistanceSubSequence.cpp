#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T, n,c;
    cin>>T>>n>>c;
    while(T--){
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        sort(nums.begin(), nums.end());
        int res=0, left=0, right=nums[n-1]-nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=1, last=nums[0];
            for(auto x: nums){
                if(x-last>=mid){
                    count++;
                    last=x;
                }
            }
            if(count>=c){
                res=mid;
                left=mid+1;
            }
            else right=mid-1;

        }
        cout<<res<<endl;
    } 
}