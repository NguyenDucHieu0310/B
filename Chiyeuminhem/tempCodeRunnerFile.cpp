#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), res=0;
        int pro=1, i=n-1;
        for(int j=n-1; j>=0; j--){
            
            while(pro<k&&i>=0){
                pro*=nums[i];
                if(pro*nums[i]<k) i--;
            }
            //if(i==0) res++;
            res+=j-i;
            pro=pro/nums[j];
        }
        return res;
    }
};
int main(){
    vector<int> nums={10,2,5,6};
    Solution sol;
    int n=sol.numSubarrayProductLessThanK(nums, 100);
    cout<<n;
}