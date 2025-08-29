#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1,0);
        for(int i=1; i<=n; i++){
            if(nums[i-1]) v[i]=v[i-1]+1;
            else v[i]=v[i-1]-1;
        }
        //for(auto x: v) cout<<x<<" ";
        for(int sp= n/2*2; sp>1; sp-=2){    
            //cout<<sp<<endl;
            for(int i=0; i<=n-sp; i++){
                //cout<<i<<" "<<i+sp<<" "<<v[i]<<" "<<v[i+sp]<<" ";
                if(v[i]==v[i+sp]) return sp;
            }
        }
        return -1;
    }
    
};
int main(){
    vector<int> num={0,1};
    Solution sol;
    int k=sol.findMaxLength(num);
    cout<<k;
}
