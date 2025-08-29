#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int maxTime=0;
    for(int i=0; i<n; i++){
        maxTime=max(maxTime, i+nums[i]+2);
    }
    cout<<maxTime;
}