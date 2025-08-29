#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n,c;
    cin>>t>>n>>c;
    for(int i=0;i<t;i++){
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(), nums.end());
        int left=0, right=nums[n-1]-nums[0];
        int res=0;
        while(left<=right){
            int mid=(left+right)/2;
            int count=1;
            int last=nums[0];
            for(int i=1; i<n;i++){
                if(nums[i]-last>=mid){
                    count++;
                    last=nums[i];
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